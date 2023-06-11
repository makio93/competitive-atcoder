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
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    rep(i, n) cin >> xy[i].first >> xy[i].second;
    sort(all(xy));
    int res = 0;
    rep(i, n) rep3(j, i+1, n) if (xy[i].first < xy[j].first && xy[i].second < xy[j].second) {
        pair<int, int> xy1 = { xy[j].first, xy[i].second }, xy2 = { xy[i].first, xy[j].second };
        auto itr1 = lower_bound(all(xy), xy1), itr2 = lower_bound(all(xy), xy2);
        if (itr1 != xy.end() && *itr1 == xy1 && itr2 != xy.end() && *itr2 == xy2) ++res;
    }
    cout << res << endl;
    return 0;
}
