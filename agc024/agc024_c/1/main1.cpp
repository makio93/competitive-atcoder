// 学習1回目,解説AC

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
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    if (a[0] > 0) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, n-1) if (a[i+1]-a[i] > 1) {
        cout << -1 << endl;
        return 0;
    }
    ll res = 0;
    rep3r(i, 1, n) {
        if (a[i]-a[i-1] == 1) ++res;
        else res += a[i];
    }
    cout << res << endl;
    return 0;
}
