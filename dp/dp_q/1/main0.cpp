// 学習1回目,自力AC

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

ll op(ll a, ll b) { return max(a, b); }
ll e() { return 0LL; }

int main() {
    int n;
    cin >> n;
    vector<int> h(n), a(n);
    rep(i, n) {
        cin >> h[i];
        h[i]--;
    }
    rep(i, n) cin >> a[i];
    segtree<ll, op, e> st(n);
    rep(i, n) st.set(h[i], st.prod(0, h[i]) + a[i]);
    cout << st.all_prod() << endl;
    return 0;
}
