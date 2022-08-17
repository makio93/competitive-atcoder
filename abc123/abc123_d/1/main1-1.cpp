// 解説AC1

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
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    vector<ll> ab, abc;
    rep(i, min(x, k)) rep(j, min(y, k)) ab.push_back(a[i]+b[j]);
    sort(ab.rbegin(), ab.rend());
    rep(i, min(k, (int)(ab.size()))) rep(j, min(z, k)) abc.push_back(ab[i]+c[j]);
    sort(abc.rbegin(), abc.rend());
    rep(i, k) cout << abc[i] << endl;
    return 0;
}
