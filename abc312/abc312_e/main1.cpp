// 解説AC

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
    vector<int> x1(n), y1(n), z1(n), x2(n), y2(n), z2(n);
    rep(i, n) cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];
    vector ids(100, vector(100, vector(100, -1)));
    rep(i, n) rep3(xi, x1[i], x2[i]) rep3(yi, y1[i], y2[i]) rep3(zi, z1[i], z2[i]) ids[xi][yi][zi] = i;
    vector<unordered_set<int>> vst(n);
    rep(i, 100) rep(j, 100) rep(k, 100) {
        if (i-1 >= 0) {
            int lid = ids[i-1][j][k], rid = ids[i][j][k];
            if (lid != -1 && rid != -1 && lid != rid) {
                vst[lid].insert(rid);
                vst[rid].insert(lid);
            }
        }
        if (i+1 < 100) {
            int lid = ids[i][j][k], rid = ids[i+1][j][k];
            if (lid != -1 && rid != -1 && lid != rid) {
                vst[lid].insert(rid);
                vst[rid].insert(lid);
            }
        }
        if (j-1 >= 0) {
            int lid = ids[i][j-1][k], rid = ids[i][j][k];
            if (lid != -1 && rid != -1 && lid != rid) {
                vst[lid].insert(rid);
                vst[rid].insert(lid);
            }
        }
        if (j+1 < 100) {
            int lid = ids[i][j][k], rid = ids[i][j+1][k];
            if (lid != -1 && rid != -1 && lid != rid) {
                vst[lid].insert(rid);
                vst[rid].insert(lid);
            }
        }
        if (k-1 >= 0) {
            int lid = ids[i][j][k-1], rid = ids[i][j][k];
            if (lid != -1 && rid != -1 && lid != rid) {
                vst[lid].insert(rid);
                vst[rid].insert(lid);
            }
        }
        if (k+1 < 100) {
            int lid = ids[i][j][k], rid = ids[i][j][k+1];
            if (lid != -1 && rid != -1 && lid != rid) {
                vst[lid].insert(rid);
                vst[rid].insert(lid);
            }
        }
    }
    rep(i, n) cout << (int)(vst[i].size()) << endl;
    return 0;
}
