// 本番WA

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
struct combination {
	vector<mint> fact, ifact;
	combination(int n) : fact(n+1), ifact(n+1) {
		fact[0] = 1;
		for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
		ifact[n] = fact[n].inv();
		for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
	}
	mint operator()(int n, int k) {
		if (k<0 || k>n) return 0;
		return (fact[n] * ifact[k] * ifact[n-k]);
	}
};

int main() {
	int r, g, b, k;
	cin >> r >> g >> b >> k;
	int sum = (r + g + b + k) * 4;
	combination cb(sum+1);
	mint res = 0;
	rep3(i, k, min(r, g)+1) {
		int sr = r - i, sg = g - i, sb = b - (i-k);
		if (sb < 0) break;
		mint val = cb(i+sr, i) * cb(i+sg, i);
		val *= cb(i+sr+sg+sb, sb);
		res += val;
	}
	cout << res.val() << endl;
	return 0;
}
