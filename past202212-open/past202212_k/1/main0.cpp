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
    int a, b;
    ll x;
    cin >> a >> b >> x;
    if (b+(ll)a*INF <= x) {
        cout << INF << endl;
        return 0;
    }
    ll res = 0;
    int ten = 1;
    rep(i, 8) ten *= 10;
    repr(i, 9) {
        rep3r(j, 1, 10) {
            if ((ll)b*j+(ll)a*ten*j <= x) {
                res += ten * j;
                x -= (ll)b*j+(ll)a*ten*j;
            }
        }
        ten /= 10;
    }
    cout << res << endl;
    return 0;
}
