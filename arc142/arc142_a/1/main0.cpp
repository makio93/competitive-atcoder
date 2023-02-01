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

const int INF = (int)(1e9);

int main() {
    ll n, k;
    cin >> n >> k;
    string ks = to_string(k);
    if (ks.back() == '0') {
        cout << 0 << endl;
        return 0;
    }
    string rks(ks.rbegin(), ks.rend());
    if (stoll(rks) < stoll(ks)) {
        cout << 0 << endl;
        return 0;
    }
    int zcnt = 0, res = 0;
    while (stoll(ks+string(zcnt,'0')) <= n) ++res, ++zcnt;
    if (ks != rks) {
        zcnt = 0;
        while (stoll(rks+string(zcnt,'0')) <= n) ++res, ++zcnt;
    }
    cout << res << endl;
    return 0;
}
