// 自力AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    int l, r;
    cin >> l >> r;
    vector<vector<int>> plst(r+1);
    for (int i=2; i<=r; ++i) if (plst[i].empty()) for (int j=i; j<=r; j+=i) plst[j].push_back(i);
    ll res = 0;
    function<ll(int, int)> f = [&](int li, int ri) {
        if (ri <= 1) return 0LL;
        ll cnt = 0;
        rep3(i, 2, li+1) {
            int plen = plst[i].size();
            rep(j, 1<<plen) {
                int mul = 1, si = __builtin_popcount(j)%2 == 0 ? 1 : -1;
                rep(j2, plen) if ((j>>j2)&1) mul *= plst[i][j2];
                cnt += ri / mul * si;
                if (j == 0) --cnt;
            }
        }
        return cnt;
    };
    rep3(g, 2, r+1) {
        int ui = r / g, di = (l-1) / g;
        res += f(ui, ui) - f(di, ui) * 2 + f(di, di);
    }
    cout << res << endl;
    return 0;
}
