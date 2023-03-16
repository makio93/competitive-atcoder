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
    int ax, ay, bx, by, n;
    cin >> ax >> ay >> bx >> by >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    auto check = [](int sx, int sy, int tx, int ty, int x1, int y1, int x2, int y2) -> bool {
        tx -= sx; ty -= sy; x1 -= sx; y1 -= sy; x2 -= sx; y2 -= sy;
        return (tx * y1 - x1 * ty) * (ll)(tx * y2 - x2 * ty) < 0;
    };
    auto isinter = [&check](int sx, int sy, int tx, int ty, int x1, int y1, int x2, int y2) -> bool {
        return check(sx, sy, tx, ty, x1, y1, x2, y2) && check(x1, y1, x2, y2, sx, sy, tx, ty);
    };
    int res = 0;
    rep(i, n) {
        int x1 = x[i], y1 = y[i], x2 = x[(i+1)%n], y2 = y[(i+1)%n];
        if (isinter(ax, ay, bx, by, x1, y1, x2, y2)) ++res;
    }
    cout << (res/2+1) << endl;
    return 0;
}
