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
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    vector<ll> bcnt(n);
    int id = 0;
    rep(i, n) {
        while (id<n && c[id]<=b[i]) ++id;
        bcnt[i] = n - id;
    }
    repr(i, n-1) bcnt[i] += bcnt[i+1];
    ll res = 0;
    id = 0;
    rep(i, n) {
        while (id<n && b[id]<=a[i]) ++id;
        if (id < n) res += bcnt[id];
    }
    cout << res << endl;
    return 0;
}
