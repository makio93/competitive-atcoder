// 学習3回目,自力AC

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
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> aids(n, -1);
    ll x = 0, res = 0;
    vector<ll> xvals(n);
    int acnt = 0, id = 0;
    aids[id] = acnt;
    while (acnt < n) {
        ++acnt;
        x += a[id];
        int ti = x % n;
        if (aids[ti] != -1) {
            ll rval = x - xvals[aids[ti]];
            int alen = acnt - aids[ti], blen = (k-acnt) % alen;
            res = x + rval * ((k-acnt) / alen) + xvals[aids[ti]+blen] - xvals[aids[ti]];
            break;
        }
        aids[ti] = acnt;
        xvals[acnt] = x;
        id = ti;
        if (acnt == k) {
            res = xvals[acnt];
            break;
        }
    }
    cout << res << endl;
    return 0;
}
