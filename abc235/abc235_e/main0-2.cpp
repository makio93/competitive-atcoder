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

// 本番終了後,自力AC

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(m), b(m), c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		--a[i]; --b[i];
	}
	vector<int> u(q), v(q), w(q);
	rep(i, q) {
		cin >> u[i] >> v[i] >> w[i];
		--u[i]; --v[i];
	}
	dsu d(n);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	rep(i, m) que.emplace(c[i], i);
	rep(i, q) que.emplace(w[i], m+i);
	vector<bool> res(q);
	rep(i, m+q) {
		int id = que.top().second; que.pop();
		if (id < m) {
			if (!d.same(a[id], b[id])) d.merge(a[id], b[id]);
		}
		else {
			if (!d.same(u[id-m], v[id-m])) res[id-m] = true;
			else res[id-m] = false;
		}
	}
	rep(i, q) cout << (res[i] ? "Yes" : "No") << endl;
	return 0;
}
