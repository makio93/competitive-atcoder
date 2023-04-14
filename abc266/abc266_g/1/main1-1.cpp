// 学習1回目,解説AC1

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
    int r, g, b, k;
    cin >> r >> g >> b >> k;
    int n = r + g + b + k;
    r -= k; g -= k;
    combination cb(n);
    mint res = 0;
    rep(i, min(r, g)+1) res += cb.fact[r-i+g-i+b+k+i] * cb.ifact[r-i] * cb.ifact[g-i] * cb.ifact[b] * cb.ifact[k] * cb.ifact[i] * (i%2==1 ? -1 : 1);
    cout << res.val() << endl;
    return 0;
}
