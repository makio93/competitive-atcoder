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

int main() {
	ll n;
	cin >> n;
	ll res = 0, mid = 0;
	for (ll i=1; i*i<=n; ++i) {
		res += (n/i - n/(i+1)) * i;
		mid = max(mid, i);
	}
	for (ll i=1; i<=n/(mid+1); ++i) res += n / i;
	cout << res << endl;
	return 0;
}
