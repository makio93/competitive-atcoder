// 解説AC2

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
    int id = 0, pval = -1;
    bool ok = true;
    rep(i, n) {
        if (pval != a[i]) id = 0;
        if (a[i] == b[i]) {
            while (id < n) {
                if (b[id]!=a[i] && b[i]!=a[id]) {
                    swap(b[id], b[i]);
                    break;
                }
                ++id;
            }
            if (id >= n) {
                ok = false;
                break;
            }
            pval = a[i];
        }
    }
    if (ok) {
        cout << "Yes" << endl;
        rep(i, n) cout << b[i] << (i<n-1?' ':'\n');
    }
    else cout << "No" << endl;
    return 0;
}
