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
	ll n;
	cin >> n;
	int nlen = to_string(n).length();
	mint res = 0;
	if (nlen <= 1) res += mint(n) * (n+1) / 2;
	else {
		res += mint(9) * 10 / 2;
		mint ten = 1;
		rep3(i, 2, nlen) {
			ten *= 10;
			mint cnt = ten * 10 - ten;
			res += (ten + ten*10 - 1) * cnt / 2 - (ten - 1) * cnt;
		}
		ten *= 10;
		mint cnt = mint(n) - ten + 1;
		res += (ten + n) * cnt / 2 - (ten - 1) * cnt;
	}
	cout << res.val() << endl;
	return 0;
}
