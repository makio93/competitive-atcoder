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

// 自力AC

int main() {
	int n, d;
	cin >> n >> d;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll sub = 0;
	rep3(i, 1, (1LL<<n)) {
		ll bi = 0;
		int bcnt = -1;
		rep(j, n) if ((i>>j) & 1) {
			bi |= a[j];
			bcnt *= -1;
		}
		sub += (ll)(1LL<<(d-(int)(__builtin_popcountll(bi)))) * bcnt;
	}
	cout << ((ll)(1LL<<d) - sub) << endl;
	return 0;
}
