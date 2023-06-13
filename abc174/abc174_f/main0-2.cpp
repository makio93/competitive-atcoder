// 自力TLE2

#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

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

struct SegmentTree {
    int n;
    vi dat_a;
    vector<vi> dat;
    SegmentTree(vi a) {
        dat_a = a;
        n = sz(dat_a);
        int dn = 1;
        while (dn < 2*n-1) dn <<= 1;
        dat = vector<vi>(dn);
        init(0, n);
    }
    void init(int l=0, int r=0, int k=0) {
        if (l==0 && r==0) r = n;
        if (r-l == 1) dat[k].pb(dat_a[l]);
        else {
            int lch = k * 2 + 1, rch = k * 2 + 2;
            init(l, (l+r)/2, lch);
            init((l+r)/2, r, rch);
            dat[k].resize(r-l);
            merge(all(dat[lch]), all(dat[rch]), dat[k].begin());
        }
    }
    int query(int i, int j, int x, int l=-1, int r=-1, int k=0) {
        if (l==-1 && r==-1) {
            l = 0;
            r = n;
            k = 0;
        }
        if (j<=l || r<=i) return 0;
        else if (i<=l && r<=j) {
            return distance(dat[k].begin(), lower_bound(all(dat[k]), x));
        }
        else {
            int lc = query(i, j, x, l, (l+r)/2, k*2+1);
            int rc = query(i, j, x, (l+r)/2, r, k*2+2);
            return lc + rc;
        }
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vi c(n);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }
    vi last(n, -1), a(n);
    rep(i, n) {
        a[i] = last[c[i]];
        last[c[i]] = i;
    }
    SegmentTree seg(a);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        --l;
        int ans = seg.query(l, r, l);
        cout << ans << endl;
    }
    return 0;
}
