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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    dsu uf(n);
    rep(i, n) uf.merge(i, p[i]);
    int c = uf.groups().size();
    mint res = (mint(m).pow(n) - mint(m).pow(c)) / 2;
    cout << res.val() << endl;
    return 0;
}
