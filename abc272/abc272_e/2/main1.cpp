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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> vals(m);
    rep(i, n) {
        int li = a[i] + (i+1) >= 0 ? 0 : a[i] + (i+1) >= n ? -1 : (-a[i]+i) / (i+1) - 1, ri = a[i] + (ll)(i+1) * m < n ? m : (n-a[i]) / (i+1);
        if (li < m && li != -1) rep3(j, li, ri) if (a[i]+(i+1)+(ll)(i+1)*j>=0 && a[i]+(i+1)+(ll)(i+1)*j<n) { vals[j].push_back(a[i]+(i+1)+(ll)(i+1)*j); }
    }
    rep(i, m) {
        vector<bool> checked(vals[i].size());
        for (const int& ti : vals[i]) if (ti < (int)(vals[i].size())) checked[ti] = true;
        int res = 0;
        rep(j, vals[i].size()) {
            if (checked[j] && j==res) ++res;
            else break;
        }
        cout << res << endl;
    }
    return 0;
}
