#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力解答2、TLE

int main() {
	int n, m, q;
	cin >> n >> m;
	unordered_map<int, unordered_set<int>> g;
	rep(i, n) g[i].insert(i);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].insert(bi);
		g[bi].insert(ai);
	}
	cin >> q;
	vector<int> x(q), y(q);
	unordered_set<int> xlst;
	rep(i, n) xlst.insert(i);
	rep(i, q) {
		cin >> x[i] >> y[i];
		x[i]--;
		xlst.erase(x[i]);
	}
	for (int i : xlst) {
		for (int t : g[i]) if (i != t) g[t].erase(i);
		g.erase(i);
	}
	vector<int> ans(q, 1);
	unordered_map<int, int> vlst;
	repr(i, q) {
		if (!vlst.empty()) {
			if ((int)(g[x[i]].size()) <= (int)(vlst.size())) {
				for (int t : g[x[i]]) {
					if (vlst.find(t) != vlst.end()) {
						ans[vlst[t]] = y[i];
						vlst.erase(t);
						if (vlst.empty()) break;
					}
				}
			}
			else {
				for (auto itr=vlst.begin(); itr!=vlst.end(); ) {
					if (g[x[i]].find(itr->first) != g[x[i]].end()) {
						ans[itr->second] = y[i];
						itr = vlst.erase(itr);
						if (vlst.empty()) break;
					}
					else ++itr;
				}
			}
		}
		vlst[x[i]] = i;
	}
	rep(i, q) cout << ans[i] << endl;
	return 0;
}
