// 学習2回目,自力AC

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

mint choose(ll ai, ll bi) {
    if (bi > ai) return 0;
    if (ai-bi < bi) return choose(ai, ai-bi);
    mint res = 1;
    for (ll i=0; i<bi; ++i) res *= ai-i;
    for (ll i=1; i<=bi; ++i) res /= i;
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll asum = k;
    rep3(i, 1, n) asum += a[i];
    if ((ll)a[0] < asum) {
        cout << 0 << endl;
        return 0;
    }
    a[0] -= asum;
    mint res = 1;
    rep(i, n) res *= choose(a[i]+k-1, k-1);
    cout << res.val() << endl;
    return 0;
}
