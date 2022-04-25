// 復習0,解説AC

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
    int h, w, k;
    cin >> h >> w >> k;
    vector<int> a(h), b(w);
    rep(i, h) cin >> a[i];
    rep(i, w) cin >> b[i];
    ll asum = 0, bsum = 0;
    rep(i, h) asum += a[i];
    rep(i, w) bsum += b[i];
    if (asum%k != bsum%k) {
        cout << -1 << endl;
        return 0;
    }
    ll asub = 0, bsub = 0;
    rep(i, h) asub += ((ll)(k-1)*w%k - a[i] + k) % k;
    rep(i, w) bsub += ((ll)(k-1)*h%k - b[i] + k) % k;
    ll res = (ll)h*w*(k-1) - max(asub, bsub);
    cout << res << endl;
    return 0;
}
