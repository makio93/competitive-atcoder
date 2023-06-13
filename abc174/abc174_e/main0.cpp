// 本番WA

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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0, den = (ll)k + n;
    rep(i, n) sum += a[i];
    VSORT(a);
    reverse(all(a));
    double ans = 0.0;
    int i = 0;
    while (k > 0) {
        double cnt = (double)sum / den;
        ll sep = max((ll)((a[i] + 0.5 * cnt) / cnt), 2LL);
        ans = max(ans, (double)(a[i])/sep);
        k -= (sep-1);
        ++i;
    }
    while (i < n) {
        ans = max(ans, (double)a[i]);
        ++i;
    }
    ll ians = ceil(ans) + 0.5;
    cout << ians << endl;
    return 0;
}
