#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説を見て実装、AC

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<ll, int> vcnt;
    vcnt[0]++;
    ll nval = 0, res = 0;
    rep(i, n) {
        if (i%2 == 0) nval += a[i];
        else nval -= a[i];
        res += vcnt[nval];
        vcnt[nval]++;
    }
    cout << res << endl;
    return 0;
}
