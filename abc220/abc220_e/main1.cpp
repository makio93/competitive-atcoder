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

using mint = modint998244353;

int main() {
	ll n, d;
	cin >> n >> d;
    mint res = 0;
    rep3(i, 1, n+1) {
        mint val = 0;
        if (i+d <= n) {
            val += mint(2).pow(d) * 2;
            if (d-2 >= 0) val += mint(2).pow(d-2) * (d-1) * 2;
        }
        else if (i+(d+1)/2 <= n) {
            ll li = n - i, ri = d - li;
            if (d-2 >= 0) val += mint(2).pow(d-2) * (li-ri+1) * 2;
        }
        res += val * mint(2).pow(i-1);
    }
    cout << res.val() << endl;
    return 0;
}
