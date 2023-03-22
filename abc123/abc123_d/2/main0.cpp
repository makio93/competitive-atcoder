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

const int INF = (int)(1e9);

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    vector<ll> bc;
    bc.reserve(y*z);
    rep(i, y) rep(j, z) bc.push_back(b[i]+c[j]);
    sort(all(bc), greater<ll>());
    vector<ll> abc;
    int bcl = min(k, y*z);
    abc.reserve(x*bcl);
    rep(i, x) rep(j, bcl) abc.push_back(a[i]+bc[j]);
    sort(all(abc), greater<ll>());
    rep(i, k) cout << abc[i] << endl;
    return 0;
}
