// 復習0,解説AC

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
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    vector<ll> x(n+2);
    rep3(i, 2, n+2) x[i] = s[i-2] - x[i-2] - x[i-1];
    vector<ll> ai(2, LINF);
    rep(i, 2) for (int j=i; j<n+2; j+=3) ai[i] = min(ai[i], x[j]);
    rep(i, 2) ai[i] *= -1;
    bool ok = true;
    for (int i=2; i<n+2; i+=3) if (x[i]-ai[0]-ai[1] < 0) ok = false;
    if (!ok) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, 2) for (int j=i; j<n+2; j+=3) x[j] += ai[i];
    for (int i=2; i<n+2; i+=3) x[i] -= ai[0] + ai[1];
    cout << "Yes" << endl;
    rep(i, n+2) printf("%lld%c", x[i], (i<n+1?' ':'\n'));
    return 0;
}
