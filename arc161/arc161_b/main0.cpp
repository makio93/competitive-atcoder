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

const int INF = (int)(1e9);
ll to3(ll n) {
	while (__builtin_popcountll(n) > 3) n -= (n & -n);
	return n;
}

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll n;
		cin >> n;
		while (n>0 && __builtin_popcountll(n)<3) --n;
		if (n == 0) cout << -1 << endl;
		else cout << to3(n) << endl;
	}
	return 0;
}
