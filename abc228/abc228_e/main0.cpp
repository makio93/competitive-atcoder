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

using mint = modint998244353;

int main() {
	ll n, k, m;
	cin >> n >> k >> m;
	if (m == 1) {
		cout << 1 << endl;
		return 0;
	}
	mint res = m;
	res = res.pow(mint(k).pow(n).val());
	cout << res.val() << endl;
	return 0;
}
