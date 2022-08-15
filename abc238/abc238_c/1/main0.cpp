// 学習1回目,自力AC

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

const ll mod = 998244353LL;
using mint = modint998244353;

int main() {
	ll n;
	cin >> n;
	int nlen = to_string(n).length();
	mint res = 0, nine = 0, pnine = 0;
	rep(i, nlen-1) {
		pnine = nine;
		nine = nine * 10 + 9;
		mint slen = nine - pnine;
		res += (1+slen) * slen / 2;
	}
	mint slen = (mint)(n) - nine;
	res += (1+slen) * slen / 2;
	cout << res.val() << endl;
	return 0;
}
