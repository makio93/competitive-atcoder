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
const ll mod = 998244353LL;
using mint = modint998244353;
struct combination {
    vector<mint> fact, ifact;
    combination(int n) : fact(n+1), ifact(n+1) {
        fact[0] = 1;
        for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
        ifact[n] = fact[n].inv();
        for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        if (k<0 || k>n) return 0;
        return (fact[n] * ifact[k] * ifact[n-k]);
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    combination cb(n);
    vector<int> deg(n);
    rep(i, m) {
        int ui, vi;
        cin >> ui >> vi;
        --ui; --vi;
        deg[ui]++; deg[vi]++;
    }
    vector<int> dcnt(2);
    rep(i, n) dcnt[deg[i]%2]++;
    mint res = 0;
    for (int i=0; i<=k; i+=2) res += cb(dcnt[1], i) * cb(dcnt[0], k-i);
    cout << res.val() << endl;
    return 0;
}
