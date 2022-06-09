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

const ll LINF = (ll)(1e18);

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    vector<ll> x = { 0, 0 };
    rep(i, n) x.push_back(s[i]-x[i]-x[i+1]);
    vector<ll> c(3, LINF);
    rep(i, n+2) c[i%3] = min(c[i%3], x[i]);
    ll csum = 0;
    rep(i, 3) csum += c[i];
    if (csum < 0) {
        cout << "No" << endl;
        return 0;
    }
    vector<ll> add = { -c[0], -c[1], c[0]+c[1] };
    vector<ll> a(n+2);
    rep(i, n+2) a[i] = x[i] + add[i%3];
    cout << "Yes" << endl;
    rep(i, n+2) cout << a[i] << (i<n+1?' ':'\n');
    return 0;
}
