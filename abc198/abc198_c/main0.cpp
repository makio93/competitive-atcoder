// 本番AC

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

int main(){
    ll r, x, y;
    cin >> r >> x >> y;
    if (x*x+y*y < r*r) {
        cout << 2 << endl;
        return 0;
    }
    ll d = (ll)sqrt(x*x+y*y);
    ll ans = d / r;
    while ((ans*r)*(ans*r) < x*x+y*y) ++ans;
    cout << ans << endl;
    return 0;
}
