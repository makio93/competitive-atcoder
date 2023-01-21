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

const int INF = (int)(1e9);
const ll LINF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<vector<int>> dist(n, vector<int>(n, INF));
	vector<vector<ll>> vals(n, vector<ll>(n, -LINF));
	queue<int> que;
	rep(i1, n) {
		dist[i1][i1] = 0;
		vals[i1][i1] = a[i1];
		que.push(i1);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dist[i1][vi], ndi = di + 1;
			ll val = vals[i1][vi];
			rep(ti, n) if (s[vi][ti] == 'Y') {
				if (dist[i1][ti] < ndi) continue;
				ll nval = val + a[ti];
				if (dist[i1][ti] == ndi) {
					vals[i1][ti] = max(vals[i1][ti], nval);
					continue;
				}
				vals[i1][ti] = max(vals[i1][ti], nval);
				dist[i1][ti] = ndi;
				que.push(ti);
			}
		}
	}
	int q;
	cin >> q;
	rep(i1, q) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		if (dist[ui][vi] == INF) {
			cout << "Impossible" << endl;
			continue;
		}
		cout << dist[ui][vi] << ' ' << vals[ui][vi] << endl;
	}
	return 0;
}
