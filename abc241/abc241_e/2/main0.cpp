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

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n), rcnt(n, -1);
    vector<ll> xsum;
    rep(i, n) cin >> a[i];
    ll x = 0;
    for (ll i=0; i<k; ++i) {
        if (rcnt[x%n] != -1) {
            ll p = i - rcnt[x%n], q = (k-i) / p, r = (k-i) % p;
            x += (x-xsum[i-p]) * q + (xsum[i-p+r]-xsum[i-p]);
            break;
        }
        rcnt[x%n] = i;
        xsum.push_back(x);
        x += a[x%n];
    }
    cout << x << endl;
    return 0;
}
