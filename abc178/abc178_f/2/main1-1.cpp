// 解説AC1

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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<int> acnt(n+1), bcnt(n+1);
    rep(i, n) acnt[a[i]]++;
    rep(i, n) bcnt[b[i]]++;
    rep(i, n) acnt[i+1] += acnt[i];
    rep(i, n) bcnt[i+1] += bcnt[i];
    bool res = true;
    int xval = 0;
    rep3(i, 1, n+1) {
        if (acnt[i]-acnt[i-1]+bcnt[i]-bcnt[i-1] > n) {
            res = false;
            break;
        }
        xval = max(xval, acnt[i]-bcnt[i-1]);
    }
    if (!res) {
        cout << "No" << endl;
        return 0;
    }
    vector<int> blst(n);
    rep(i, n) blst[(i+xval)%n] = b[i];
    cout << "Yes" << endl;
    rep(i, n) cout << blst[i] << (i<n-1?' ':'\n');
    return 0;
}
