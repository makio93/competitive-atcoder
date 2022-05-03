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

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<int> alst = a, blst = b;
    sort(all(alst));
    sort(all(blst));
    ll res = 0;
    rep(i, n) res += abs(a[i]-alst[n/2]);
    rep(i, n) res += abs(b[i]-blst[n/2]);
    rep(i, n) res += b[i] - a[i];
    cout << res << endl;
    return 0;
}
