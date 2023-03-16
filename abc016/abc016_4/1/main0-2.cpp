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

const double PI = acos(-1);
const double DINF = 1e18;

int main() {
    int ax, ay, bx, by, n;
    cin >> ax >> ay >> bx >> by >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    auto sp = [](int& x1, int& y1, int& x2, int& y2) -> void {
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (x1==x2 && y1>y2) swap(y1, y2);
    };
    sp(ax, ay, bx, by);
    auto isy = [&](int x1, int y1, int x2, int y2) -> bool {
        sp(x1, y1, x2, y2);
        double ta = atan2(by-ay, bx-ax), t1 = atan2(y1-ay, x1-ax), t2 = atan2(y2-ay, x2-ax);
        t1 -= ta;
        t2 -= ta;
        if (t1 > PI) t1 -= PI*2.0;
        if (t1 <= -PI) t1 += PI*2.0;
        if (t2 > PI) t2 -= PI*2.0;
        if (t2 <= -PI) t2 += PI*2.0;
        if (t1*t2 > 0.0) return false;
        double sa = atan2(y2-y1, x2-x1), s1 = atan2(ay-y1, ax-x1), s2 = atan2(by-y1, bx-x1);
        s1 -= sa;
        s2 -= sa;
        if (s1 > PI) s1 -= PI*2.0;
        if (s1 <= -PI) s1 += PI*2.0;
        if (s2 > PI) s2 -= PI*2.0;
        if (s2 <= -PI) s2 += PI*2.0;
        return (s1*s2 <= 0.0);
    };
    int res = 0;
    rep(i, n) {
        int x1 = x[i], x2 = x[(i+1)%n], y1 = y[i], y2 = y[(i+1)%n];
        if (isy(x1, y1, x2, y2)) ++res;
    }
    cout << (res/2+1) << endl;
    return 0;
}
