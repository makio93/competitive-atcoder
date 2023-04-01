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
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    int res = 0;
    rep(i, n) rep3(j, i+1, n) rep3(k, j+1, n) {
        int x1 = x[j] - x[i], y1 = y[j] - y[i], x2 = x[k] - x[i], y2 = y[k] - y[i];
        ll val = abs((ll)x1*y2-(ll)x2*y1);
        if (val!=0 && val%2==0) ++res;
    }
    cout << res << endl;
    return 0;
}
