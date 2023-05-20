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
	int n, q;
	cin >> n >> q;
	vector<unordered_set<int>> g(n);
	unordered_set<int> sst;
	rep(i, n) sst.insert(i);
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int ui, vi;
			cin >> ui >> vi;
			--ui; --vi;
			if (sst.find(ui) != sst.end()) sst.erase(ui);
			if (sst.find(vi) != sst.end()) sst.erase(vi);
			g[ui].insert(vi);
			g[vi].insert(ui);
		}
		else {
			int vi;
			cin >> vi;
			--vi;
			for (const int& ti : g[vi]) {
				g[ti].erase(vi);
				if (g[ti].empty()) sst.insert(ti);
			}
			g[vi].clear();
			sst.insert(vi);
		}
		cout << (int)(sst.size()) << endl;
	}
	return 0;
}
