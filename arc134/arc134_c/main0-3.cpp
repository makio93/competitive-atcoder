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

// 本番AC

using mint = modint998244353;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll rsum = 0;
	rep3(i, 1, n) rsum += a[i];
	if (a[0]-k-rsum < 0LL) {
		cout << 0 << endl;
		return 0;
	}
	a[0] -= k;
	a[0] -= rsum;
	mint res = 1;
	rep(i, n) {
		ll nval = a[i]+k-1, kval = k-1;
		if (kval > nval-kval) kval = nval - kval;
		for (int ai=0; ai<(int)kval; ++ai) res *= ((mint)nval-ai);
		for (int bi=1; bi<=(int)kval; ++bi) res /= bi;
	}
	cout << res.val() << endl;
	return 0;
}
