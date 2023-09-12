// 解説AC

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

const int INF = (int)(1e9);

int main() {
    int l, r;
    cin >> l >> r;
    ll res = 0;
    rep3(i, 2, r+1) {
        bool ok = true;
        int ti = i, pcnt = 0;
        for (int j=2; j*j<=ti; ++j) if (ti%j == 0) {
            int cnt = 0;
            while (ti%j == 0) {
                ti /= j;
                ++cnt;
            }
            if (cnt > 1) ok = false;
            ++pcnt;
        }
        if (ti > 1) ++pcnt;
        if (!ok) continue;
        int a = r / i - (l-1) / i, mul = pcnt % 2 == 1 ? 1 : -1;
        res += a * (ll)(a-1) / 2 * mul;
    }
    rep3(i, max(2, l), r+1) res -= r / i - 1;
    res *= 2;
    cout << res << endl;
    return 0;
}
