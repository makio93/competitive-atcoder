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

const ll LINF = (ll)(1e18);

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    vector<ll> a(n+2);
    rep3(i, 2, n+2) a[i] = s[i-2] - a[i-2] - a[i-1];
    vector<ll> mvals(3, LINF);
    rep(i, n+2) mvals[i%3] = min(mvals[i%3], a[i]);
    ll msum = 0;
    rep(i, 3) msum += mvals[i];
    if (msum < 0) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, 3) if (mvals[i] > 0) {
        ll sub = min(mvals[i], msum);
        mvals[i] -= sub;
        msum -= sub;
    }
    rep(i, n+2) a[i] -= mvals[i%3];
    cout << "Yes" << endl;
    rep(i, n+2) cout << a[i] << (i<n+1?' ':'\n');
    return 0;
}
