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

// 解説AC

bool check2(ll x, ll y, ll s, ll t) {
    rep(i, 2) {
        if ((s+x-1)/x+(t+x-1)/x <= y) return true;
        swap(x, y);
    }
    return false;
}

bool check3(ll x, ll y, ll a, ll b, ll c) {
    rep(i, 2) {
        rep(j, 3) {
            ll yi = (a+x-1) / x;
            if (yi<y && check2(x,y-yi,b,c)) return true;
            swap(a, b); swap(b, c);
        }
        swap(x, y);
    }
    return false;
}

int main() {
	ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    cout << (check3(x,y,a,b,c) ? "Yes" : "No") << endl;
	return 0;
}
