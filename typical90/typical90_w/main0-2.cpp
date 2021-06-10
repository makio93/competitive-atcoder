#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力で作成、途中まで作ったけど力尽きた

const ll mod = (ll)(1e9) + 7;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    vector<vector<int>> b(h, vector<int>(w));
    rep(i, h) rep(j, w) b[i][j] = (c[i][j] == '.') ? 2 : 1;
    vector<vector<vector<ll>>> dpl(h, vector<vector<ll>>(w, vector<ll>(2, 0)));
    vector<vector<vector<ll>>> dpr(h, vector<vector<ll>>(w, vector<ll>(2, 0)));
    dpl[0][0][0] = 1;
    if (b[0][0] == 1) dpl[0][0][1] = 1;
    rep(i, h) rep(j, w) rep(k, b[i][j]) {
        const vector<int> di = { -1, -1, -1, 0 }, dj = { -1, 0, 1, -1 };
        const vector<pair<int>> tar = { { 0, 1 }, { 0, 3 }, { 1, 2 }, { 1, 3 } };
        ll kval = 0;
        vector<int> pid, pch(4);
        int pl = 0;
        rep(i2, 4) {
            int ni = i + di[i2], nj = j + dj[i2];
            if (ni<0 || ni>=h || nj<0 || nj>=w) continue;
            pid.push_back(i2);
            pch[i2] = 1;
            ++pl;
        }
        rep(i2, (1<<pl)) {
            vector<int> cl(pl), cch(4);
            rep(j2, pl) {
                cl[j2] = ((i2>>j2) & 1) ? 1 : 0;
                cch[pid[j2]] = cl[j2];
            }
            bool app = true;
            rep(j2, pl) {
                int ni = i + di[pid[j2]], nj = j + dj[pid[j2]];
                if (cl[j2] >= b[ni][nj]) {
                    app = false;
                    break;
                }
            }
            if (k>0 && app) {
                int ccnt = 0;
                rep(j2, pl) ccnt += cl[j2];
                if (ccnt > 0) app = false;
            }
            if (app) {
                rep(j2, (int)(tar.size())) if (pch[tar[j2][0]]==1 && pch[tar[j2][1]]==1) {
                    if (cch[tar[j2][0]]+cch[tar[j2][1]] >= 2) {
                        app = false;
                        break;
                    } 
                }
            }
            if (app) {
                ll nval3 = (pch[0]==1) ? ((dpl[i+di[0]][j+dj[0]][0] + dpl[i+di[0]][j+dj[0]][1]) % mod) : 0;
                ll nval1a = (pch[2]==1) ? ((dpl[i+di[2]][j+dj[2]][cch[2]] + (mod - nval3)) % mod) : 0;
                ll nval1b = (pch[1]==1) ? ((dpl[i+di[1]][j+dj[1]][1-cch[1]] + (mod - nval3)) % mod) : 0;
                ll nval1 = (nval1a + (mod - nval1b)) % mod;
                ll nval2a = (pch[3]==1) ? (dpl[i+di[3]][j+dj[3]][cch[3]]) : 0;
                ll nval2b = (pch[0]==1) ? (dpl[i+di[0]][j+dj[0]][1-cch[0]]) : 0;
                ll nval2 = (nval2a + (mod - nval2b)) % mod;
                ll nval = nval1 * nval2 % mod;
                dpl[i][j][k] = nval;
            }
        }
    }
    return 0;
}
