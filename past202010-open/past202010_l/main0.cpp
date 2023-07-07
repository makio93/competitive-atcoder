// バチャ本番AC

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
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n, q;
    cin >> n >> q;
    vll h(n);
    rep(i, n) cin >> h[i];
    map<ll, int> ceven, codd;
    rep(i, n-1) {
        ll sub = h[i+1] - h[i];
        if (i%2==0) codd[sub]++;
        else ceven[sub]++;
    }
    ll teven = 0, todd = 0;
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            ll v;
            cin >> v;
            todd += v;
            teven -= v;
        }
        else if (t == 2) {
            ll v;
            cin >> v;
            todd -= v;
            teven += v;
        }
        else {
            int u;
            ll v;
            cin >> u >> v;
            --u;
            if (u%2==0) {
                if (u+1<n) {
                    ll sub = h[u+1] - h[u];
                    codd[sub]--;
                    sub -= v;
                    codd[sub]++;
                }
                if (u-1>=0) {
                    ll sub = h[u] - h[u-1];
                    ceven[sub]--;
                    sub += v;
                    ceven[sub]++;
                }
            }
            else {
                if (u+1<n) {
                    ll sub = h[u+1] - h[u];
                    ceven[sub]--;
                    sub -= v;
                    ceven[sub]++;
                }
                if (u-1>=0) {
                    ll sub = h[u] - h[u-1];
                    codd[sub]--;
                    sub += v;
                    codd[sub]++;
                }
            }
            h[u] += v;
        }
        cout << (codd[todd] + ceven[teven]) << endl;
    }
    return 0;
}
