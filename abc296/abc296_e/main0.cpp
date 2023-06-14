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
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int>> g(n);
	vector<int> din(n);
	rep(i, n) {
		g[i].push_back(a[i]);
		din[a[i]]++;
	}
	queue<int> que;
	rep(i, n) if (din[i] == 0) que.push(i);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		for (const int& ti : g[vi]) if (din[ti] > 0) {
			din[ti]--;
			if (din[ti] == 0) que.push(ti);
		}
	}
	int res = 0;
	rep(i, n) if (din[i] > 0) ++res;
	cout << res << endl;
	return 0;
}
