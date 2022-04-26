// 復習1,自力AC

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
    auto at = a, bt = b;
    sort(all(at)); sort(all(bt));
    if (at != bt) {
        cout << "No" << endl;
        return 0;
    }
    at.erase(unique(all(at)), at.end());
    if ((int)(at.size()) != n) {
        cout << "Yes" << endl;
        return 0;
    }
    int acnt = 0, bcnt = 0;
    rep(i, n-1) rep3(j, i+1, n) if (a[i] > a[j]) ++acnt;
    rep(i, n-1) rep3(j, i+1, n) if (b[i] > b[j]) ++bcnt;
    if (acnt%2 == bcnt%2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
