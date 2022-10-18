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
    int n, x0, y0, x2, y2;
    cin >> n >> x0 >> y0 >> x2 >> y2;
    double xq = (x0+x2) / 2.0, yq = (y0+y2) / 2.0;
    double r = sqrt((x0-xq)*(x0-xq)+(y0-yq)*(y0-yq));
    double v0 = atan2(y0-yq, x0-xq), v1 = v0 + acos(-1) * 2.0 / n;
    if (v1 > acos(-1)) v1 -= acos(-1) * 2.0;
    double x1 = xq + cos(v1) * r, y1 = yq + sin(v1) * r;
    cout << fixed << setprecision(11) << x1 << ' ' << y1 << endl;
    return 0;
}
