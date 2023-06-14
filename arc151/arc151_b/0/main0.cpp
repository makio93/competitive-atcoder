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
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	mint res = 0;
	dsu d(n);
	int gcnt = n;
	rep(i, n) {
		int ai = i, bi = p[i];
		if (!d.same(ai, bi)) {
			res += mint(m) * (m-1) / 2 * mint(m).pow(gcnt-2);
			d.merge(ai, bi);
			--gcnt;
		}
	}
	cout << res.val() << endl;
	return 0;
}
