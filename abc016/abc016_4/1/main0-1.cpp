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

const double DINF = 1e18;

int main() {
    int ax, ay, bx, by, n;
    cin >> ax >> ay >> bx >> by >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    auto isy = [](int x1, int y1, int x2, int y2, int tx) -> double {
        int li = x1, ri = x2;
        if (tx<li || tx>ri) return DINF;
        if (li == ri) return (double)min(y1, y2);
        return y1 + (y2-y1) * double(tx-x1) / (x2-x1);
    };
    if (ax > bx) {
        swap(ax, bx);
        swap(ay, by);
    }
    int res = 0;
    rep(i, n) {
        int x1 = x[i], x2 = x[(i+1)%n], y1 = y[i], y2 = y[(i+1)%n];
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            if (ax == bx) continue;
            auto r1 = isy(ax, ay, bx, by, x1);
            if (r1!=DINF && r1>=(double)y1 && r1<=(double)y2) ++res;
            continue;
        }
        int li = max(x1, ax), ri = min(x2, bx);
        auto r1 = isy(x1, y1, x2, y2, li), r2 = isy(x1, y1, x2, y2, ri);
        if (r1==DINF || r2==DINF) continue;
        if (r1 > r2) swap(r1, r2);
        if (r2<=(double)max(ay, by) && r1>=(double)min(ay, by)) ++res;
    }
    cout << (res/2+1) << endl;
    return 0;
}
