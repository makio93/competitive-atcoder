// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n, m;
    cin >> n >> m;
    vi h(n), w(m);
    rep(i, n) cin >> h[i];
    rep(i, m) cin >> w[i];
    VSORT(h); VSORT(w);
    vll lsum(n+2), rsum(n+2);
    rep(i, n) {
        if (i == 0) continue;
        lsum[i+1] = lsum[i-1] + (h[i]-h[i-1]);
    }
    repr(i, n) {
        if (i == n-1) continue;
        rsum[i+1] = rsum[i+3] + (h[i+1]-h[i]);
    }
    ll ans = INF2;
    rep(i, n) {
        if (i%2==1) continue;
        ll sum = lsum[i] + rsum[i+2];
        int mi = distance(w.begin(), lower_bound(all(w), h[i]));
        ll val = INF2;
        if (w[mi] == h[i]) val = 0;
        else {
            if (mi==m) val = llabs((ll)h[i] - w[m-1]);
            else if (mi == 0) val = llabs((ll)w[mi]-h[i]);
            else val = min(llabs((ll)h[i]-w[mi]), llabs((ll)h[i]-w[mi-1]));
        }
        ans = min(ans, sum+val);
    }
    cout << ans << endl;
    return 0;
}
