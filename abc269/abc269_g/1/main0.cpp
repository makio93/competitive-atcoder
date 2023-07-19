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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    unordered_map<int, int> vcnt(n);
    rep(i, n) vcnt[b[i]-a[i]]++;
    vector<pair<int, int>> vlst;
    for (auto [val, cnt] : vcnt) {
        int id = 1;
        while (cnt >= id) {
            vlst.emplace_back(val*id, id);
            cnt -= id;
            id <<= 1;
        }
        if (cnt > 0) vlst.emplace_back(val*cnt, cnt);
    }
    int vlen = vlst.size();
    vector<int> dp(m+1, INF);
    dp[accumulate(all(a), 0)] = 0;
    rep(i, vlen) {
        auto ndp = dp;
        rep(j, m+1) if (dp[j] < INF && j+vlst[i].first >= 0 && j+vlst[i].first <= m) chmin(ndp[j+vlst[i].first], dp[j]+vlst[i].second);
        swap(dp, ndp);
    }
    rep(i, m+1) cout << (dp[i] == INF ? -1 : dp[i]) << endl;
    return 0;
}
