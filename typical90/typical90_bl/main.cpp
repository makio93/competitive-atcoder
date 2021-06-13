#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1), b(n+1);
    rep(i, n) cin >> a[i];
    rep(i, n) b[i+1] = a[i+1] - a[i];
    ll val = 0;
    rep(i, n-1) val += llabs(b[i+1]);
    rep(i, q) {
        int li, ri; ll vi;
        cin >> li >> ri >> vi;
        --li;
        ll lsub = (li > 0) ? (llabs(b[li]+vi)-llabs(b[li])) : 0;
        ll rsub = (ri < n) ? (llabs(b[ri]-vi)-llabs(b[ri])) : 0;
        b[li] += vi; b[ri] -= vi;
        val += lsub + rsub;
        cout << val << endl;
    }
    return 0;
}
