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
	ll n;
	cin >> n;
	ll res = 0;
	for (ll a=1; a*a*a<=n; ++a) for (ll b=a; a*b*b<=n; ++b) {
		ll cl = b, cr = n / (a*b);
		if (cr >= cl) res += cr - cl + 1;
	}
	cout << res << endl;
	return 0;
}
