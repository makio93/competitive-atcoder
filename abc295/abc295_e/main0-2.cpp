// 自力WA

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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> b;
	int zcnt = 0;
	rep(i, n) {
		if (a[i] != 0) b.push_back(a[i]);
		else ++zcnt;
	}
	sort(all(b));
	mint res = 0;
	int len = b.size();
	if (zcnt == 0) {
		res = b[k-1];
		cout << res.val() << endl;
		return 0;
	}
	combination cb(n+m+1);
	rep(i, len+1) {
		int li = (i-1 < 0) ? 1 : b[i-1], ri = (i >= len) ? m : b[i];
		int lcnt = k - i - 1, rcnt = (n - k) - (len - i);
		if (lcnt>=0 && lcnt<=zcnt && rcnt>=0 && rcnt<=zcnt) {
			rep3(j, li, ri+1) {
				res += mint(j) * (mint(1) / m) * cb(zcnt, 1) * (mint(j)/m).pow(lcnt) * cb(zcnt-1, lcnt) * (mint(m-j)/m).pow(rcnt);
			}
		}
		if (i < len) {
			rcnt = (n - k) - (len - (i + 1));
			if (lcnt>=0 && lcnt<=zcnt && rcnt>=0 && rcnt<=zcnt) {
				res += mint(b[i]) * (mint(b[i])/m).pow(lcnt) * cb(zcnt, lcnt) * (mint(m-b[i])/m).pow(rcnt);
			}
		}
	}
	cout << res.val() << endl;
	return 0;
}
