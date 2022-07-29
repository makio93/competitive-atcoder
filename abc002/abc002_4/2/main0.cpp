// 復習2回目,自力AC

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
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    rep(i, m) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    vector<int> frs(n);
    rep(i, m) {
        frs[x[i]] |= 1<<y[i];
        frs[y[i]] |= 1<<x[i];
    }
    rep(i, n) frs[i] |= 1<<i;
    int res = 0;
    rep3(i, 1, 1<<n) {
        bool ok = true;
        rep(j, n) if (((i>>j)&1) && (i&frs[j])!=i) {
            ok = false;
            break;
        }
        if (ok) res = max(res, __builtin_popcount(i));
    }
    cout << res << endl;
    return 0;
}
