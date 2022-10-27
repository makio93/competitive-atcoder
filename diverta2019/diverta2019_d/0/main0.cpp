// バチャ参加,自力AC

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
	ll n;
	cin >> n;
	ll res = 0;
	for (ll i=1; i*i<=n; ++i) {
		ll li = n / (i+1) + 1, ri = n / i + 1;
		while (ri-li > 1) {
			ll ci = li + (ri-li) / 2;
			if (n%ci >= i) li = ci;
			else ri = ci;
		}
		if (n%li == i) res += li;
	}
	cout << res << endl;
	return 0;
}
