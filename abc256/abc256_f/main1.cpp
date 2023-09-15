// 解説AC

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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	fenwick_tree<mint> ft0(n), ft1(n), ft2(n);
	function<void(int, int)> update = [&](int id, int val) {
		ft0.add(id, (mint)val);
		ft1.add(id, val*(mint)(id+1));
		ft2.add(id, val*(mint)(id+1)*(id+1));
	};
	rep(i, n) update(i, a[i]);
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int xi, vi;
			cin >> xi >> vi;
			--xi;
			update(xi, -a[xi]);
			a[xi] = vi;
			update(xi, a[xi]);
		}
		else {
			int xi;
			cin >> xi;
			--xi;
			mint res = ft2.sum(0, xi+1) / 2;
			res -= ft1.sum(0, xi+1) * (2 * (xi+1) + 3) / 2;
			res += ft0.sum(0, xi+1) * (xi + 2) * (xi + 3) / 2;
			cout << res.val() << endl;
		}
	}
	return 0;
}
