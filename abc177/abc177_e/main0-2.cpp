// 終了後,自力AC

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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int m = 0;
    rep(i, n) m = max(m, a[i]);
    vi prime(m+1);
    for (int i=2; i<=m; ++i) {
        if (prime[i]!=0) continue;
        for (int j=i; j<=m; j+=i) prime[j] = i;
    }
    int res = a[0];
    rep1(i, n-1) res = gcd(res, a[i]);
    if (res != 1) {
        cout << "not coprime" << endl;
        return 0;
    }
    vector<bool> exist(m+1);
    rep(i, n) {
        if (a[i] == 1) continue;
        while (a[i] > 1) {
            if (exist[prime[a[i]]]) {
                cout << "setwise coprime" << endl;
                return 0;
            }
            else {
                exist[prime[a[i]]] = true;
                int tmpa = a[i];
                while (tmpa%prime[a[i]]==0) tmpa /= prime[a[i]];
                a[i] = tmpa;
            }
        }
    }
    cout << "pairwise coprime" << endl;
    return 0;
}
