// 本番提出,WA

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

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	vector<vector<int>> g(n);
	dsu dg(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
		dg.merge(ai, bi);
	}
	bool ok = true;
	rep(i, n) if ((int)(g[i].size()) > d[i]) ok = false;
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	auto lst = dg.groups();
	if ((int)(lst.size()) == 1) {
		if (m == n-1) cout << endl;
		else cout << -1 << endl;
		return 0;
	}
	unordered_map<int, vector<int>> memo;
	rep(i, n) {
		if (d[i] > (int)(g[i].size())) {
			rep(j, (d[i]-(int)(g[i].size()))) memo[dg.leader(i)].push_back(i);
		}
	}
	vector<int> vcnt1;
	vector<vector<int>> vcnt2;
	for (auto pi : memo) {
		if ((int)(pi.second.size()) > 2) {
			cout << -1 << endl;
			return 0;
		}
		if ((int)(pi.second.size()) == 2) {
			vector<int> tmp;
			rep(i, 2) tmp.push_back(pi.second[i]);
			vcnt2.push_back(tmp);
		}
		else if ((int)(pi.second.size()) == 1) {
			vcnt1.push_back(pi.second[0]);
		}
	}
	if ((int)(vcnt1.size()) != 2) {
		cout << -1 << endl;
		return 0;
	}
	vector<pair<int, int>> res;
	res.emplace_back(vcnt1[0]+1, vcnt2[0][0]+1);
	res.emplace_back(vcnt1[1]+1, vcnt2.back()[1]+1);
	int rlen = vcnt2.size();
	rep(i, rlen-1) {
		res.emplace_back(vcnt2[i][1]+1, vcnt2[i+1][0]+1);
	}
	int alen = res.size();
	rep(i, alen) cout << res[i].first << ' ' << res[i].second << endl;
	return 0;
}
