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

const int INF = (int)(1e9);

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int b, k, sx, sy, gx, gy;
        cin >> b >> k >> sx >> sy >> gx >> gy;
        ll res = (abs(gx-sx) + abs(gy-sy)) * (ll)k;
        const vector<int> sxlst = { sx/b*b, (sx+b-1)/b*b, sx, sx }, sylst = { sy, sy, sy/b*b, (sy+b-1)/b*b },
            gxlst = { gx/b*b, (gx+b-1)/b*b, gx, gx }, gylst = { gy, gy, gy/b*b, (gy+b-1)/b*b };
        rep(i, 4) {
            int sxi = sxlst[i], syi = sylst[i];
            ll sval = (abs(sxi-sx) + abs(syi-sy)) * (ll)k;
            rep(j, 4) {
                int gxi = gxlst[j], gyi = gylst[j];
                ll gval = (abs(gxi-gx) + abs(gyi-gy)) * (ll)k;
                if (sxi%b==0 && gxi%b==0 && syi%b!=0 && gyi%b!=0 && syi/b==gyi/b) {
                    ll tval = abs(gxi-sxi) * (ll)k + abs(gyi-syi);
                    tval = min(tval, (ll)abs(gxi-sxi)+syi%b+gyi%b);
                    tval = min(tval, (ll)abs(gxi-sxi)+(b-syi%b)+(b-gyi%b));
                    res = min(res, sval+gval+tval);
                }
                else if (sxi%b!=0 && gxi%b!=0 && syi%b==0 && gyi%b==0 && sxi/b==gxi/b) {
                    ll tval = abs(gyi-syi) * (ll)k + abs(gxi-sxi);
                    tval = min(tval, (ll)abs(gyi-syi)+sxi%b+gxi%b);
                    tval = min(tval, (ll)abs(gyi-syi)+(b-sxi%b)+(b-gxi%b));
                    res = min(res, sval+gval+tval);
                }
                else {
                    ll tval = abs(gxi-sxi) + (ll)abs(gyi-syi);
                    res = min(res, sval+gval+tval);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
