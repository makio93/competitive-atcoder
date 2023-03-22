// 本番,WA

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
struct SegmentTree {
	int n;
	vector<pair<int, int>> dat;
	SegmentTree() { init(1); }
	SegmentTree(int n_) { init(n_); }
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat = vector<pair<int, int>>(2*n-1, { 0, -1 });
	}
	void update(int k, int a) {
		int id = k;
		k += n-1;
		dat[k] = { a, id };
		while (k > 0) {
			k = (k-1) / 2;
			dat[k] = max(dat[k*2+1], dat[k*2+2]);
		}
	}
	pair<int, int> query(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) { r = n; k = 0; l = 0; }
		if (r<=a || b<=l) return { 0, -1 };
		if (a<=l && r<=b) return dat[k];
		else {
			pair<int, int> vl = query(a, b, k*2+1, l, (l+r)/2);
			pair<int, int> vr = query(a, b, k*2+2, (l+r)/2, r);
			return max(vl, vr);
		}
	}
};


int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	SegmentTree st(n);
	rep(i, n) st.update(i, p[i]);
	vector<vector<ll>> memo(n+1, vector<ll>(n+1, -1));
	auto calc = [&](auto calc, int li, int ri) -> ll {
		if (memo[li][ri] != -1) return memo[li][ri];
		if (ri-li <= 1) return memo[li][ri] = 1;
		else {
			auto tar = st.query(li, ri);
			int ci = tar.second;
			ll lval = 0, rval = 0;
			while (ci > li) {
				lval = (lval + calc(calc, li, ci)) % mod;
				--ci;
			}
			lval = (lval + 1) % mod;
			ci = tar.second + 1;
			while (ci < ri) {
				rval = (rval + calc(calc, ci, ri)) % mod;
				++ci;
			}
			rval = (rval + 1) % mod;
			ll aval = (lval * rval) % mod;
			return memo[li][ri] = aval;
		}
	};
	cout << calc(calc, 0, n) << endl;
	return 0;
}
