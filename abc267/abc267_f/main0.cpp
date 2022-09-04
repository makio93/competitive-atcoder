// 本番WA

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
	int n, q;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> pre(n, -1), post(n, -1);
	int lid = 0, rid = 0;
	auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
		pre[vi] = lid;
		++lid;
		for (int ti : g[vi]) if (ti != pi) dfs(dfs, ti, vi);
		post[vi] = rid;
		++rid;
	};
	dfs(dfs);
	unordered_map<int, unordered_set<int>> prevec, postvec;
	rep(i, n) {
		prevec[pre[i]].insert(i);
		postvec[post[i]].insert(i);
	}
	cin >> q;
	rep(i, q) {
		int ui, ki;
		cin >> ui >> ki;
		--ui;
		int lid = pre[ui], rid = post[ui], res = -1;
		if (prevec.find(lid+ki) != prevec.end()) {
			for (const int& tid : prevec[lid+ki]) if (rid-post[tid] >= ki) {
				res = tid;
				break;
			}
		}
		if (res==-1 && prevec.find(lid-ki)!=prevec.end()) {
			for (const int& tid : prevec[lid-ki]) if (post[tid]-rid >= ki) {
				res = tid;
				break;
			}
		}
		if (res==-1 && postvec.find(rid+ki)!=postvec.end()) {
			for (const int& tid : postvec[rid+ki]) if (lid-pre[tid] >= ki) {
				res = tid;
				break;
			}
		}
		if (res==-1 && postvec.find(rid-ki)!=postvec.end()) {
			for (const int& tid : postvec[rid-ki]) if (pre[tid]-lid >= ki) {
				res = tid;
				break;
			}
		}
		if (res == -1) cout << -1 << endl;
		else cout << (res+1) << endl;
	}
	return 0;
}
