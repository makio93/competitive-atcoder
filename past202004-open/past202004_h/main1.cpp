// 解説AC

#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct P {
    int r, c;
    P(int r, int c) : r(r), c(c) {}
};

int main(){
    int n, m;
    cin >> n >> m;
    vs a(n);
    rep(i, n) cin >> a[i];
    vector<vector<P>> gp(11);
    rep(i, n) rep(j, m) {
        int d;
        if (a[i][j]=='S') d = 0;
        else if (a[i][j]=='G') d = 10;
        else d = a[i][j] - '0';
        gp[d].emplace_back(i, j);
    }
    vector<vi> dp(n, vi(m, INF));
    P s = gp[0].back();
    dp[s.r][s.c] = 0;
    rep1(i, 10) {
        for (P j : gp[i]) {
            int mn = INF;
            for (P k : gp[i-1]) {
                if (dp[k.r][k.c]==INF) continue;
                mn = min(mn, dp[k.r][k.c]+abs(j.r-k.r)+abs(j.c-k.c));
            }
            if (mn==INF) continue;
            dp[j.r][j.c] = mn;
        }
    }
    P g = gp[10].back();
    cout << (dp[g.r][g.c]!=INF?dp[g.r][g.c]:-1) << endl;
    return 0;
}
