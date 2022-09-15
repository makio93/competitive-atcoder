// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

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

int main(){
    int h, w;
    cin >> h >> w;
    vs s(h);
    rep(i, h) cin >> s[i];
    vector<vi> dp(h+1, vi(w+1, INF));
    rep(i, h) rep(j, w) {
        if (i==0 && j==0) dp[i+1][j+1] = (s[i][j]=='.'?0:1);
        else {
            if (i-1<0 || s[i][j]==s[i-1][j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1]);
            else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1]+1);
            if (j-1<0 || s[i][j]==s[i][j-1]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]);
            else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]+1);
        }
    }
    int ans = dp[h][w] + (s[h-1][w-1]=='.'?0:1);
    ans /= 2;
    cout << ans << endl;
    return 0;
}
