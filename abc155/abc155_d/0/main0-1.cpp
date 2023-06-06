// 自力WA

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
    int n;
    ll k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi pos, neg, zero;
    rep(i, n) {
        if (a[i] > 0) pos.pb(a[i]);
        else if (a[i] < 0) neg.pb(a[i]);
        else zero.pb(a[i]);
    }
    int ps = sz(pos), ns = sz(neg), zs = sz(zero);
    priority_queue<ll, vll, greater<ll>> q;
    if (k <= (ll)ns*ps) {
        rep(i, ns) rep(j, ps) {
            q.push((ll)neg[i]*pos[j]);
        }
    }
    else if (k <= (ll)ns*ps+zs*(ps+ns)+zs*(zs-1)/2) {
        k = 1;
        q.push(0);
    }
    else {
        k -= (ll)ns*ps+zs*(ps+ns)+zs*(zs-1)/2;
        rep(i, ns) for (int j=i+1; j<ns; ++j) q.push((ll)neg[i]*neg[j]);
        rep(i, ps) for (int j=i+1; j<ps; ++j) q.push((ll)pos[i]*pos[j]);
    }
    rep(i, k-1) q.pop();
    ll ans = q.top();
    cout << ans << endl;
    return 0;
}
