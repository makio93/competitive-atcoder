// 自力AC

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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    reverse(all(b));
    int dval = 0;
    rep(i, n) if (a[i] == b[i]) {
        dval = a[i];
        break;
    }
    bool res = true;
    if (dval != 0) {
        int ali = n, ari = -1, bli = n, bri = -1;
        rep(i, n) {
            if (a[i] == dval) {
                ali = min(ali, i);
                ari = max(ari, i);
            }
            if (b[i] == dval) {
                bli = min(bli, i);
                bri = max(bri, i);
            }
        }
        int dli = max(ali, bli), dri = min(ari, bri);
        if (dri >= dli) {
            if (max(ari,bri)-min(ali,bli)+dri-dli+2 > n) res = false;
            else rep(i, dri-dli+1) swap(b[dli+i], b[(max(ari,bri)+1+i)%n]);
        }
    }
    if (res) {
        cout << "Yes" << endl;
        rep(i, n) cout << b[i] << (i<n-1?' ':'\n');
    }
    else cout << "No" << endl;
    return 0;
}
