// 自力AC,学習3回目

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
    priority_queue<int> nlst;
    ll res = -LINF, val = 0;
    repr(i, n+1) {
        if (t[i] == 2) {
            if (y[i] >= 0) val += y[i];
            else {
                nlst.push(y[i]);
                if ((int)(nlst.size()) > k) {
                    val += nlst.top();
                    nlst.pop();
                }
            }
        }
        else {
            res = max(res, y[i]+val);
            --k;
            if (k < 0) break;
            if ((int)(nlst.size()) > k) {
                val += nlst.top();
                nlst.pop();
            }
        }
    }
    cout << res << endl;
    return 0;
}
