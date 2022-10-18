// 学習1回目,解説AC

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

const int INF = (int)(1.5e9);

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> s(n), t(n), x(n), d(q);
    rep(i, n) cin >> s[i] >> t[i] >> x[i];
    rep(i, q) cin >> d[i];
    vector<tuple<int, int, int>> events;
    rep(i, n) {
        events.emplace_back(s[i]-x[i], 1, x[i]);
        events.emplace_back(t[i]-x[i], -1, x[i]);
    }
    sort(all(events));
    vector<int> res(q);
    multiset<int> xst;
    int elen = events.size(), id = 0;
    rep(i, q) {
        while (id<elen && get<0>(events[id])<=d[i]) {
            if (get<1>(events[id]) == 1) xst.insert(get<2>(events[id]));
            else xst.erase(xst.find(get<2>(events[id])));
            ++id;
        }
        if (xst.empty()) res[i] = -1;
        else res[i] = *xst.begin();
    }
    rep(i, q) cout << res[i] << endl;
    return 0;
}
