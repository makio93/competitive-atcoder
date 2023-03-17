// 解説AC1

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
	vector<int> x(m), y(m), din(n);
	vector<vector<int>> g(n);
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		g[xi].push_back(yi);
		din[yi]++;
	}
	bool ok = true;
	vector<int> dist(n, -INF);
	queue<int> que;
	int nval = 0;
	rep(i, n) if (din[i] == 0) {
		que.push(i);
		if ((int)(que.size()) > 1) {
			ok = false;
			break;
		}
	}
	while (!que.empty() && ok) {
		int vi = que.front(); que.pop();
		dist[vi] = nval++;
		for (const int& ti : g[vi]) if (din[ti] > 0) {
			din[ti]--;
			if (din[ti] == 0) {
				que.push(ti);
				if ((int)(que.size()) > 1) {
					ok = false;
					break;
				}
			}
		}
	}
	if (!ok) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		rep(i, n) cout << (dist[i]+1) << (i<n-1?' ':'\n');
	}
	return 0;
}
