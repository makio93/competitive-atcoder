#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<int> da, db;
    for (int i=1; i*i<=a[0]; ++i) {
        if (a[0]%i == 0) {
            da.push_back(i);
            if (i != a[0]/i) da.push_back(a[0]/i);
        }
    }
    for (int i=1; i*i<=b[0]; ++i) {
        if (b[0]%i == 0) {
            db.push_back(i);
            if (i != b[0]/i) db.push_back(b[0]/i);
        }
    }
    sort(all(da)); sort(all(db));
    ll res = 0;
    for (int d1 : da) for (int d2 : db) {
        bool ok = true;
        rep3(i, 1, n) if ((a[i]%d1!=0||b[i]%d2!=0) && (a[i]%d2!=0||b[i]%d1!=0)) ok = false;
        if (ok) res = max(res, lcm((ll)d1, (ll)d2));
    }
    cout << res << endl;
    return 0;
}
