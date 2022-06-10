// 復習1回目,自力AC

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
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> bcnt(30);
    rep(i, n) rep(j, 30) if ((a[i]>>j)&1) bcnt[j]++;
    ll res = 0;
    rep(i, n) res += a[i];
    rep(i, n) {
        ll val = 0;
        rep(j, 30) {
            if ((a[i]>>j)&1) val += (1<<j) * (ll)(n-bcnt[j]);
            else val += (1<<j) * (ll)bcnt[j];
        }
        res = max(res, val);
    }
    cout << res << endl;
    return 0;
}
