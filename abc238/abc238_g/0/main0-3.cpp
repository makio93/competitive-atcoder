// 復習0,自力3,TLE+RE

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

vector<unordered_map<int, int>> pcnt;
vector<int> plst;
unordered_set<int> pst;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    pcnt = vector<unordered_map<int, int>>(n);
    rep(i, n) {
        int at = a[i];
        for (int j=2; j*j<=at; ++j) if (at%j == 0) {
            pst.insert(j);
            while (at%j == 0) {
                pcnt[i][j]++;
                at /= j;
            }
        }
        if (at > 1) {
            pst.insert(at);
            pcnt[i][at]++;
        }
    }
    for (int vi : pst) plst.push_back(vi);
    sort(all(plst));
    int m = plst.size();
    vector<vector<int>> psum(n+1, vector<int>(m));
    rep(i, n) for (auto pi : pcnt[i]) {
        int id = lower_bound(all(plst), pi.first) - plst.begin();
        psum[i+1][id] += pi.second;
    }
    rep(i, m) rep(j, n) psum[j+1][i] += psum[j][i];
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        bool ok = true;
        rep(j, m) if ((psum[ri][j]-psum[li][j])%3 != 0) {
            ok = false;
            break;
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
