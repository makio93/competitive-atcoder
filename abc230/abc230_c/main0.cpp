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

// 本番AC

int main() {
	ll n, a, b, p, q, r, s;
	cin >> n >> a >> b >> p >> q >> r >> s;
	ll kl1 = max(1-a, 1-b), kr1 = min(n-a, n-b), kl2 = max(1-a, b-n), kr2 = min(n-a, b-1);
	vector<string> res((int)(q-p+1), string((int)(s-r+1), '.'));
	for (ll i=p; i<=q; ++i) for (ll j=r; j<=s; ++j) {
		bool blk = false;
		if (kr1-kl1>=0 && i-a==j-b && i-a>=kl1 && i-a<=kr1) blk = true;
		if (kr2-kl2>=0 && i-a==-(j-b) && i-a>=kl2 && i-a<=kr2) blk = true;
		if (blk) res[i-p][j-r] = '#';
	}
	rep(i, (int)(q-p+1)) cout << res[i] << endl;
	return 0;
}
