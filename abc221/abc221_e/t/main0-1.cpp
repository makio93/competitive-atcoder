// 練習1

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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> atmp = a;
    sort(all(atmp));
    atmp.erase(unique(all(atmp)), atmp.end());
    rep(i, n) a[i] = lower_bound(all(atmp), a[i]) - atmp.begin();
    int m = atmp.size();
    fenwick_tree<mint> fw(m);
    mint res = 0;
    rep(i, n) {
        if (i-1 >= 0) res += mint(2).pow(i-1) * fw.sum(0, a[i]+1);
        fw.add(a[i], mint(2).pow(i).inv());
    }
    cout << res.val() << endl;
    return 0;
}
