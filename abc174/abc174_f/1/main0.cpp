// 学習1回目,自力AC

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
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }
    vector<int> l(q), r(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
        l[i]--;
    }
    vector<vector<int>> clst(n);
    rep(i, n) clst[c[i]].push_back(i);
    vector<int> cids(n), ord(q);
    iota(all(ord), 0);
    sort(all(ord), [&](int li, int ri) -> bool { return l[li] < l[ri]; });
    fenwick_tree<int> ft(n);
    rep(i, n) if (!clst[i].empty()) ft.add(clst[i][0], 1);
    vector<int> res(q);
    int li = 0;
    rep(i, q) {
        while (li<n && li<l[ord[i]]) {
            ft.add(li, -1);
            cids[c[li]]++;
            if (cids[c[li]] < (int)(clst[c[li]].size())) ft.add(clst[c[li]][cids[c[li]]], 1);
            ++li;
        }
        res[ord[i]] = ft.sum(l[ord[i]], r[ord[i]]);
    }
    rep(i, q) cout << res[i] << endl;
    return 0;
}
