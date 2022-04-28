// 練習1,自力AC

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

int main() {
    int n;
    cin >> n;
    vector<int> c(1<<n);
    rep3(i, 1, (1<<n)) cin >> c[i];
    vector<pair<int, int>> clst;
    rep(i, (1<<n)) clst.emplace_back(c[i], i);
    sort(all(clst));
    unordered_set<int> used;
    used.insert(0);
    ll res = 0;
    rep(i, (1<<n)) if (used.find(clst[i].second) == used.end()) {
        res += clst[i].first;
        unordered_set<int> add;
        for (int ui : used) add.insert(ui^clst[i].second);
        for (int ai : add) used.insert(ai);
    }
    cout << res << endl;
    return 0;
}
