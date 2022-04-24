// 復習1,自力AC

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

using mint = modint998244353;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    rep3(i, 1, n) sum += a[i];
    if ((ll)a[0] < sum+k) {
        cout << 0 << endl;
        return 0;
    }
    a[0] -= sum + k;
    mint res = 1;
    rep(i, n) if (a[i] > 0) {
        ll ai = k + a[i] - 1, bi = k - 1;
        if (bi > ai-bi) bi = ai - bi;
        mint val = 1;
        for (int j=0; j<bi; ++j) val *= ai - j;
        for (int j=1; j<=bi; ++j) val /= j;
        res *= val;
    }
    cout << res.val() << endl;
    return 0;
}
