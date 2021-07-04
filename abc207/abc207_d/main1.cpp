#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

const double eps = (1e-6);

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n) cin >> c[i] >> d[i];
    if (n == 1) { cout << "Yes" << endl; return 0; }
    int asum = 0, bsum = 0, csum = 0, dsum = 0;
    rep(i, n) {
        asum += a[i]; bsum += b[i]; csum += c[i]; dsum += d[i];
        a[i] *= n; b[i] *= n; c[i] *= n; d[i] *= n;
    }
    rep(i, n) { a[i] -= asum; b[i] -= bsum; c[i] -= csum; d[i] -= dsum; }
    rep(i, n) if (a[i]!=0 && b[i]!=0) { swap(a[i], a[0]); swap(b[i], b[0]); break; }
    bool res = false;
    rep(i, n) {
        double theta = atan2(d[i], c[i]) - atan2(b[0], a[0]);
        bool zero = (c[i]==0 && d[i]==0), ok = true;
        rep(j, n) {
            double a2 = a[j] * cos(theta) - b[j] * sin(theta);
            double b2 = b[j] * cos(theta) + a[j] * sin(theta);
            bool ok2 = false;
            rep(j2, n) {
                if (zero && ((j==0&&j2==i)||(j==i&&j2==0))) ok2 = true;
                if (!zero && abs(c[j2]-a2)<=eps && abs(d[j2]-b2)<=eps) ok2 = true;
            }
            if (!ok2) ok = false;
        }
        if (ok) { res = true; break; }
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
