// 自力TLE1

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
const int mval = 55555 * 5, smval = 55555;

int main() {
	int n;
	cin >> n;
	vector<int> plst;
	unordered_set<int> tlst;
	vector<bool> vmemo(mval+1);
	for (int i=2; i<=mval; ++i) if (!vmemo[i]) {
		if (i <= smval) plst.push_back(i);
		tlst.insert(i);
		for (int j=i*2; j<=mval; j+=i) vmemo[j] = true;
	}
	vector<int> res;
	vector<unordered_set<int>> slst(4);
	int plen = plst.size();
	auto dfs = [&](auto dfs, int di=0, int id=0) -> bool {
		if (di == n) return true;
		if (id >= plen) return false;
		while (id < plen) {
			bool ok = true;
			int nval = plst[id];
			for (int tval : slst[3]) if (tlst.find(tval+nval) != tlst.end()) {
				ok = false;
				break;
			}
			if (!ok) {
				++id;
				continue;
			}
			vector<unordered_set<int>> subs(4);
			repr(ii, 3) {
				for (int tval : slst[ii]) if (slst[ii+1].find(tval+nval) == slst[ii+1].end()) subs[ii+1].insert(tval+nval);
				for (int tval : subs[ii+1]) slst[ii+1].insert(tval);
			}
			subs[0].insert(nval);
			slst[0].insert(nval);
			res.push_back(nval);
			if (dfs(dfs, di+1, id+1)) return true;
			rep(ii, 4) for (int tval : subs[ii]) slst[ii].erase(tval);
			res.pop_back();
		}
		return false;
	};
	dfs(dfs);
	rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	return 0;
}
