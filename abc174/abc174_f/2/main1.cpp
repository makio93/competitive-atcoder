// 学習2回目,解説AC

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
    vector<tuple<int, int, int>> lr(q);
    rep(i, q) {
        cin >> get<0>(lr[i]) >> get<1>(lr[i]);
        get<0>(lr[i])--; get<1>(lr[i])--;
        get<2>(lr[i]) = i;
    }
    sort(all(lr), [](auto& ai, auto& bi) -> bool { return get<1>(ai) < get<1>(bi); });
    vector<int> cv(n, -1);
    fenwick_tree<int> fw(n);
    int id = 0;
    vector<int> res(q);
    rep(i, n) {
        if (cv[c[i]] != -1) fw.add(cv[c[i]], -1);
        cv[c[i]] = i;
        fw.add(i, 1);
        while (id<q && get<1>(lr[id])<=i) {
            res[get<2>(lr[id])] = fw.sum(get<0>(lr[id]), get<1>(lr[id])+1);
            ++id;
        }
    }
    rep(i, q) cout << res[i] << endl;
    return 0;
}
