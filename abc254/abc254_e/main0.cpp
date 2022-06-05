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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<vector<int>> sums(n, vector<int>(4));
	vector<unordered_map<int, int>> dist(n);
	rep(i, n) {
		queue<int> que;
		dist[i][i] = 0;
		sums[i][0] += i+1;
		que.push(i);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dist[i][vi], ndi = di + 1;
			for (int ti : g[vi]) if (dist[i].find(ti) == dist[i].end()) {
				dist[i][ti] = ndi;
				sums[i][ndi] += ti + 1;
				if (ndi < 3) que.push(ti);
			}
		}
		rep(j, 3) sums[i][j+1] += sums[i][j];
	}
	int q;
	cin >> q;
	rep(i, q) {
		int xi, ki;
		cin >> xi >> ki;
		--xi;
		cout << sums[xi][ki] << endl;
	}
	return 0;
}
