// 自力AC

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
	ll n, m, p;
	cin >> n >> m >> p;
	auto modpow = [](auto modpow, ll n, ll p, ll m) -> ll {
		if (p == 0) return 1 % m;
		if (p%2 == 0) {
			ll t = modpow(modpow, n, p/2, m);
			return t * t % m;
		}
		else {
			return n * modpow(modpow, n, p-1, m) % m;
		}
	};
	cout << modpow(modpow, n, p, m) << endl;
	return 0;
}
