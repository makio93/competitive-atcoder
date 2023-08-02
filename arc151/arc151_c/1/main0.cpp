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
    ll n;
    int m;
    cin >> n >> m;
    vector<ll> x(m);
    vector<int> y(m);
    rep(i, m) cin >> x[i] >> y[i];
    if (m == 0) {
        if (n%2 == 0) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
    else {
        ll xval = 0;
        xval ^= x[0] - 1;
        xval ^= n - x[m-1];
        rep(i, m-1) if (y[i+1] == y[i]) xval ^= 1;
        if (xval == 0) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
    return 0;
}
