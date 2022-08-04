// 自力AC

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

int main() {
    ll k;
    cin >> k;
    int n = 50;
    vector<ll> res(n);
    ll q = k / n + (n-1);
    int r = (int)(k % n);
    rep(i, r) res[i] = q + n + 1 - r;
    rep3(i, r, n) res[i] = q - r;
    cout << n << endl;
    rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
    return 0;
}
