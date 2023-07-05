// 自力TLE2

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
    int n, m;
    cin >> n >> m;
    v(v(bool)) g(n, v(bool)(n));
    rep(i, n) g[i][i] = true;
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi;
        ai--; bi--;
        g[ai][bi] = g[bi][ai] = true;
    }
    v(set<int>) groups(n);
    rep(i1, n) {
        v(bool) check(n);
        check[i1] = true;
        rep(i, n) if (g[i1][i]) check[i] = true;
        rep(i, n) {
            if (i == i1) continue;
            if (!check[i]) continue;
            rep2(j, i+1, n-1) {
                if (j == i1) continue;
                if (!check[j]) continue;
                if (!g[i][j]) check[j] = false;
            }
        }
        check[i1] = true;
        rep(i, n) if (check[i]) groups[i1].insert(i);
    }
    vp(int) gsize(n);
    rep(i, n) gsize[i] = { sz(groups[i]), i };
    RSORT(gsize);
    v(bool) used(n);
    int cnt = 0;
    rep(i, n) {
        int id = gsize[i].second;
        if (!used[id]) {
            ++cnt;
            used[id] = true;
            repi(itr, groups[id]) used[*itr] = true;
        }
    }
    cout << cnt << endl;
    return 0;
}
