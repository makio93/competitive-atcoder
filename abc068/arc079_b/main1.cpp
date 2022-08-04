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

int main() {
    ll k;
    cin >> k;
    int n = 50;
    vector<ll> res(n);
    rep(i, n) res[i] = k / n + i;
    k %= n;
    rep(i, k) {
        res[i] += n;
        rep(j, n) if (j != i) res[j]--;
    }
    cout << n << endl;
    rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
    return 0;
}
