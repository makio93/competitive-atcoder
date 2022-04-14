// 練習1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    map<int, unordered_set<int>> rid;
    map<int, set<pair<int, int>>> lid;
    rep(i, n) rid[r[i]].insert(i);
    rep(i, n) lid[l[i]].emplace(r[i], i);
    int res = 0;
    while (!rid.empty()) {
        int tar = rid.begin()->first + d - 1;
        auto litr = lid.begin();
        while (!lid.empty() && litr->first<=tar) {
            for (auto pi : litr->second) {
                rid[pi.first].erase(pi.second);
                if (rid[pi.first].empty()) rid.erase(pi.first);
            }
            litr = lid.erase(litr);
        }
        ++res;
    }
    cout << res << endl;
    return 0;
}
