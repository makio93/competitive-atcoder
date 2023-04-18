// 

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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    int mval = *max_element(all(a));
    vector<ll> acnt(mval+1);
    rep(i, n) acnt[a[i]] += b[i];
    ll res = 0;
    rep(i, mval+1) {
        if (k <= acnt[i]) {
            res = i;
            break;
        }
        k -= acnt[i];
    }
    cout << res << endl;
    return 0;
}
