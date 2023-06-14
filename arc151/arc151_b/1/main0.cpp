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

using mint = modint998244353;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    dsu uf(n);
    mint res = 0;
    int slen = n;
    rep(i, n) {
        if (uf.same(i, p[i])) continue;
        res += mint(m) * (m-1) / 2 * mint(m).pow(slen-2);
        uf.merge(i, p[i]);
        --slen;
    }
    cout << res.val() << endl;
    return 0;
}
