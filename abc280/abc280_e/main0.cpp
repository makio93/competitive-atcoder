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
	int n, p;
	cin >> n >> p;
	map<int, mint> memo;
	auto calc = [&](auto calc, int ni) -> mint {
		if (memo.find(ni) != memo.end()) return memo[ni];
		if (ni <= 1) return memo[ni] = ni;
		else {
			mint rval = (p * (calc(calc, ni-2) + 1) + (100-p) * (calc(calc, ni-1) + 1)) / 100;
			return memo[ni] = rval;
		}
	};
	cout << calc(calc, n).val() << endl;
	return 0;
}
