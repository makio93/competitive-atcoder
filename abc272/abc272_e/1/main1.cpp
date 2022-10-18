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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> vlsts(m);
    rep(i, n) if (a[i]+(i+1) < n) {
        int li = (a[i] >= 0) ? 1 : ((-a[i]+i)/(i+1));
        while (li<=m && a[i]+(i+1)*li<n) {
            vlsts[li-1].push_back(a[i]+(i+1)*li);
            ++li;
        }
    }
    vector<int> res(m);
    rep(i, m) {
        int tlen = vlsts[i].size();
        vector<bool> exists(tlen);
        rep(j, tlen) if (vlsts[i][j] < tlen) exists[vlsts[i][j]] = true;
        while (res[i]<tlen && exists[res[i]]) res[i]++;
    }
    rep(i, m) cout << res[i] << endl;
    return 0;
}
