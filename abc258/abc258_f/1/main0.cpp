// 学習1回目,自力WA

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
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int b, k, sx, sy, gx, gy;
        cin >> b >> k >> sx >> sy >> gx >> gy;
        if (make_pair(sx, sy) > make_pair(gx, gy)) swap(sx, gx), swap(sy, gy);
        if (gy >= sy) {
            int tx = sx / b * b, ty = sy / b * b;
            sx -= tx, sy -= ty;
            gx -= tx, gy -= ty;
        }
        else {
            int tx = sx / b * b, ty = (sy+b-1) / b * b;
            sx -= tx, sy -= ty;
            gx -= tx, gy -= ty;
            sy = -sy, gy = -gy;
        }
        ll res = ((gx - sx) + (gy - sy)) * (ll)k;
        int sx2 = sx / b * b, sy2 = sy / b * b, gx2 = gx / b * b, gy2 = gy / b * b;
        vector<int> dx = { 0, b, 0, b }, dy = { 0, 0, b, b };
        rep(i1, 4) {
            int sxi = sx2 + dx[i1], syi = sy2 + dy[i1];
            ll sval = min(abs(sx-sxi), abs(sy-syi)) * (ll)(sx%b==0||sy%b==0 ? 1 : k) + max(abs(sx-sxi), abs(sy-syi));
            rep(i2, 4) {
                int gxi = gx2 + dx[i2], gyi = gy2 + dy[i2];
                ll gval = min(abs(gx-gxi), abs(gy-gyi)) * (ll)(gx%b==0||gy%b==0 ? 1 : k) + max(abs(gx-gxi), abs(gy-gyi));
                res = min(res, sval+gval+abs(gxi-sxi)+abs(gyi-syi));
            }
        }
        cout << res << endl;
    }
    return 0;
}
