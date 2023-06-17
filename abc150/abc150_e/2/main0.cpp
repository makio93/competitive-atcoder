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

using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    sort(c.rbegin(), c.rend());
    mint res = 0;
    rep(i, n) res += (mint(2).pow(i) + (i-1 >= 0 ? mint(2).pow(i-1) * i : 0)) * c[i] * mint(2).pow(n-1-i);
    res *= mint(2).pow(n);
    cout << res.val() << endl;
    return 0;
}
