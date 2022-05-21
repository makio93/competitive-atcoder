// 学習1回目,解説AC1

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
    rep3(i, 1, n+1) if (acnt[i]+bcnt[i] > n) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, n) acnt[i+1] += acnt[i];
    rep(i, n) bcnt[i+1] += bcnt[i];
    int x = 0;
    rep(i, n) x = max(x, acnt[i+1]-bcnt[i]);
    rep(i, n) if (x > acnt[i]-bcnt[i+1]+n) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep(i, n) printf("%d%c", b[(i-x+n)%n], (i<n-1?' ':'\n'));
    return 0;
}
