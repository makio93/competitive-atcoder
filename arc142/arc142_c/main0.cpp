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

int main() {
	int n;
	cin >> n;
	vector<vector<int>> dist(n, vector<int>(2));
	bool one = true;
	rep3(i, 2, n) {
		rep(j, 2) {
			cout << "? " << (i+1) << ' ' << (j+1) << endl;
			cin >> dist[i][j];
		}
		if (abs(dist[i][0]-dist[i][1]) != 1) one = false;
	}
	if (!one) {
		int res = INF;
		rep3(i, 2, n) res = min(res, dist[i][0]+dist[i][1]);
		cout << "! " << res << endl;
		return 0;
	}
	pair<int, int> uv = { -1, -1 }, dv = { n+1, n+1 };
	rep3(i, 2, n) uv = max(uv, { dist[i][0]+dist[i][1], i });
	int tid = (dist[uv.second][0] >= dist[uv.second][1]) ? 0 : 1;
	rep3(i, 2, n) if (dist[i][1-tid]>dist[i][tid] && dist[i][tid]==1) dv = min(dv, { dist[i][tid], i });
	if (dv.second == n+1) {
		cout << "! " << 1 << endl;
		return 0;
	}
	int dval = 0;
	cout << "? " << (uv.second+1) << ' ' << (dv.second+1) << endl;
	cin >> dval;
	if (dval >= dist[uv.second][tid]) cout << "! " << 1 << endl;
	else {
		int res = INF;
		rep3(i, 2, n) res = min(res, dist[i][0]+dist[i][1]);
		cout << "! " << res << endl;
	}
	return 0;
}
