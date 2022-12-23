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

const ll LINF = (ll)(1e18);

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    vector<ll> a(n+2);
    rep3(i, 2, n+2) a[i] = s[i-2] - a[i-2] - a[i-1];
    ll v1 = 0, v2 = 0;
    for (int i=0; i<n+2; i+=3) v1 = min(v1, a[i]);
    for (int i=0; i<n+2; i+=3) a[i] -= v1;
    for (int i=1; i<n+2; i+=3) v2 = min(v2, a[i]);
    for (int i=1; i<n+2; i+=3) a[i] -= v2;
    bool ok = true;
    for (int i=2; i<n+2; i+=3) {
        if (a[i]+v1+v2 < 0) {
            ok = false;
            break;
        }
        a[i] += v1 + v2;
    }
    if (ok) {
        cout << "Yes" << endl;
        rep(i, n+2) cout << a[i] << (i<n+1?' ':'\n');
    }
    else cout << "No" << endl;
    return 0;
}
