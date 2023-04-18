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

const int INF = (int)(1e9);

int main() {
    int n;
    ll p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> sum(n+1);
    rep(i, n) sum[i+1] += sum[i] + a[i];
    rep(i, n) {
        int li = i;
        auto ri = lower_bound(all(sum), p+sum[li]) - sum.begin();
        if (ri>n || sum[ri]-sum[li]>p) continue;
        li = ri;
        ri = lower_bound(all(sum), q+sum[li]) - sum.begin();
        if (ri>n || sum[ri]-sum[li]>q) continue;
        li = ri;
        ri = lower_bound(all(sum), r+sum[li]) - sum.begin();
        if (ri>n || sum[ri]-sum[li]>r) continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
