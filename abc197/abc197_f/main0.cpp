// 本番,未完成,解答不能

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
    v(v(p2(int,char))) g(n);
    rep(i, m) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].eb(b, c);
        g[b].eb(a, c);
    }
    queue<int> que1, que2;
    v(int) dist(n, (int)(INF));
    // que1.pb(0); que2.pb(n-1);
    dist[0] = 1;
    dist[n-1] = 1;
    while (!que1.empty() || !que2.empty()) {
        set<p2(int, char)> stock;
        while (!que1.empty()) {
            int pos = que1.front(); que1.pop();
            int d = dist[pos], nd = d + 1;
            rep(i2, sz(g[pos])) {
                auto tpos = g[pos][i2];
                int to = tpos.first; char tch = tpos.second;
                /* 解答不能
                if (to)
                */
            }
        }
    }
    return 0;
}