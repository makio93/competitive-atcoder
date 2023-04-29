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
const ll MX = (ll)(1e6);

int main() {
	ll n;
	cin >> n;
	ll mv = min(n, MX);
	vector<ll> plst;
	vector<bool> sieve(mv+1);
	for (ll i=2; i<=mv; ++i) if (!sieve[i]) {
		plst.push_back(i);
		for (ll j=i*i; j<=mv; j+=i) sieve[j] = true;
	}
	int m = plst.size();
	ll res = 0;
	rep(i, m) {
		ll aval = plst[i] * plst[i];
		if (aval*plst[i]*plst[i]*plst[i] > n) break;
		rep3(j, i+1, m) {
			ll bval = aval * plst[j];
			if (bval*plst[j]*plst[j] > n) break;
			rep3(k, j+1, m) {
				ll cval = bval * plst[k] * plst[k];
				if (cval > n) break;
				++res;
			}
		}
	}
	cout << res << endl;
	return 0;
}
