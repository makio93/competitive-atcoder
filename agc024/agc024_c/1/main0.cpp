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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int mval = 0;
    ll res = 0;
    repr(i, n) {
        if (a[i] < mval) {
            res = -1;
            break;
        }
        if (a[i] > mval) {
            if (a[i] > i) {
                res = -1;
                break;
            }
            res += a[i];
            mval = a[i];
        }
        mval = max(0, mval-1);
    }
    cout << res << endl;
    return 0;
}
