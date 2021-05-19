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

// 自力AC

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int d = 0;
    rep(i, q) {
        int t, x, y;
        cin >> t >> x >> y;
        --x; --y;
        if (t == 1) {
            int ax = (x + n - d%n) % n, ay = (y + n - d%n) % n;
            swap(a[ax], a[ay]);
        }
        else if (t == 2) ++d;
        else {
            int ax = (x + n - d%n) % n;
            cout << a[ax] << endl;
        }
    }
    return 0;
}
