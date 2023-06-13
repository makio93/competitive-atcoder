// 解説AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int n, q;
    cin >> n >> q;
    v(int) c(n);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }
    v(p2(p(int), int)) query(q);
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        query[i] = { { ri, li }, i };
    }
    VSORT(query);
    fenwick_tree<int> fw(n);
    v(int) rc(n, -1), ans(q);
    int qi = 0;
    rep(i, n) {
        if (rc[c[i]] != -1) fw.add(rc[c[i]], -1);
        rc[c[i]] = i;
        fw.add(i, 1);
        while (qi<q && query[qi].first.first-1==i) {
            int li = query[qi].first.second, ri = query[qi].first.first;
            ans[query[qi].second] = fw.sum(li, ri);
            ++qi;
        }
    }
    rep(i, q) cout << ans[i] << endl;
    return 0;
}
