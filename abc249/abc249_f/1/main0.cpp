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

const ll LINF = (ll)(1e18);

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> t(n+1), y(n+1);
    t[0] = 1;
    rep3(i, 1, n+1) cin >> t[i] >> y[i];
    priority_queue<ll> nvals;
    ll sum = 0, res = -LINF;
    repr(i, n+1) {
        if (t[i] == 1) {
            res = max(res, y[i]+sum);
            --k;
            if (k < 0) break;
            while ((int)(nvals.size()) > k) {
                sum += nvals.top(); nvals.pop();
            }
        }
        else {
            if (y[i] >= 0) sum += y[i];
            else {
                nvals.push(y[i]);
                while ((int)(nvals.size()) > k) {
                    sum += nvals.top(); nvals.pop();
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
