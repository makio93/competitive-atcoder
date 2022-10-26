// 学習2回目,バチャ本番AC

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

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(m), b(m), c(k), d(k), deg(n);
	dsu uf(n);
	rep(i, m) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		uf.merge(a[i], b[i]);
		deg[a[i]]++;
		deg[b[i]]++;
	}
	vector<vector<int>> blst(n);
	rep(i, k) {
		cin >> c[i] >> d[i];
		c[i]--; d[i]--;
		blst[c[i]].push_back(d[i]);
		blst[d[i]].push_back(c[i]);
	}
	vector<int> res(n);
	rep(i, n) {
		res[i] = uf.size(i) - deg[i] - 1;
		for (const int& ti : blst[i]) if (uf.same(i, ti)) res[i]--;
	}
	rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	return 0;
}
