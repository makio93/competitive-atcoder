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

// 本番WA

using mint = modint998244353;

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<int> dist1(n, INF), dist2(n, INF);
	queue<int> que;
	que.push(0);
	dist1[0] = 0;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		int d = dist1[v], nd = d + 1;
		for (int t : g[v]) if (dist1[t] > nd) {
			que.push(t);
			dist1[t] = nd;
		}
	}
	pair<int, int> mval = { -1, -1 };
	rep(i, n) mval = max(mval, { dist1[i], i });
	int r2 = mval.second, dval = mval.first;
	que.push(r2);
	dist2[r2] = 0;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		int d = dist2[v], nd = d + 1;
		for (int t : g[v]) if (dist2[t] > nd) {
			que.push(t);
			dist2[t] = nd;
		}
	}
	pair<int, int> mval2 = { -1, -1 };
	rep(i, n) mval2 = max(mval2, { dist2[i], i });
	int dval2 = mval2.first;
	mint res = 0;
	if (dval2 == dval) {
		int cnt1 = 0, cnt2 = 0;
		rep(i, n) if (dist1[i] == dval) ++cnt1;
		mint res1 = mint(2).pow(cnt1);
		rep(i, n) if (dist2[i]==dval2 && i!=0) ++cnt2;
		mint res2 = mint(2).pow(cnt2);
		res = res1 * res2 / 2;
	}
	else {
		int s3 = mval2.second;
		vector<int> dist3(n, INF);
		que.push(s3);
		dist3[s3] = 0;
		while (!que.empty()) {
			int v = que.front(); que.pop();
			int d = dist3[v], nd = d + 1;
			for (int t : g[v]) if (dist3[t] > nd) {
				que.push(t);
				dist3[t] = nd;
			}
		}
		int cnt2 = 0, cnt3 = 0;
		rep(i, n) if (dist2[i] == dval2) ++cnt2;
		mint res2 = mint(2).pow(cnt2);
		rep(i, n) if (dist3[i]==dval2 && i!=r2) ++cnt3;
		mint res3 = mint(2).pow(cnt3);
		res = res2 * res3 / 2;
	}
	cout << res.val() << endl;
	return 0;
}
