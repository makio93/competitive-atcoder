// 学習1回目,自力WA

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
    int n, a;
    cin >> n >> a;
    vector<int> w(n), x(n), v(n);
    rep(i, n) cin >> w[i] >> x[i] >> v[i];
    int xlen = max(*max_element(all(x)), a) + 1;
    xlen = xlen * 2 + 1;
    set<pair<int, int>> xst;
    vector<int> wsums(n);
    rep(i, n) xst.emplace(x[i], i);
    int wsum = 0;
    for (const auto& pi : xst) {
        wsum += w[pi.second];
        wsums[pi.second] = wsum;
    }
    int res = 0;
    rep(i, xlen+1) {
        for (auto itr=xst.begin(); itr!=xst.end(); ++itr) {
            auto titr = prev(xst.upper_bound({ itr->first+a, INF }));
            int lval = (itr == xst.begin()) ? 0 : wsums[prev(itr)->second];
            res = max(res, wsums[titr->second]-lval);
        }
        set<pair<int, int>> nst;
        for (const auto& pi : xst) nst.emplace(pi.first+v[pi.second], pi.second);
        swap(nst, xst);
        int wsum = 0;
        for (const auto& pi : xst) {
            wsum += w[pi.second];
            wsums[pi.second] = wsum;
        }
    }
    cout << res << endl;
    return 0;
}
