#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

int main() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    double psum = 0.0;
    rep(i, n) {
        double pi = 1.0 / (r[i] - l[i] + 1);
        rep3(j, l[i], r[i]+1) rep(i2, n) if (i2 != i) {
            double pi2 = 1.0 / (r[i2] - l[i2] + 1);
            if (i2 < i) {
                int cnt = (j < l[i2]) ? (r[i2] - l[i2] + 1) : max(0, r[i2]-j);
                psum += pi * pi2 * cnt;
            }
            else {
                int cnt = (j > r[i2]) ? (r[i2] - l[i2] + 1) : max(0, j-l[i2]);
                psum += pi * pi2 * cnt;
            }
        }
    }
    printf("%.12f\n", psum/2.0);
    return 0;
}
