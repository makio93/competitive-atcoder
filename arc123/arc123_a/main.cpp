#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const ll LINF = (ll)(1e18);

int main() {
	ll a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	ll res = LINF;
	ll b1 = a2 + (a2 - a3), b3 = a2 + (a2 - a1), b2 = (a1 + a3 + 1) / 2;
	bool odd = (abs(a1 - a3) % 2 == 1);
	if (b1 >= a1) res = min(res, b1-a1);
	if (b3 >= a3) res = min(res, b3-a3);
	if (b2 >= a2) {
		ll c2 = b2 - a2;
		if (odd) c2++;
		res = min(res, c2);
	}
	cout << res << endl;
	return 0;
}
