// 終了後,自力AC

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
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> qlst(q, vector<int>(1));
	rep(i, q) {
		cin >> qlst[i][0];
		if (qlst[i][0] == 1) {
			int li, ri, xi;
			cin >> li >> ri >> xi;
			--li;
			for (int vi : { li, ri, xi }) qlst[i].push_back(vi);
		}
		else if (qlst[i][0] == 2) {
			int id, xi;
			cin >> id >> xi;
			--id;
			for (int vi : { id, xi }) qlst[i].push_back(vi);
		}
		else {
			int yi, xi;
			cin >> yi >> xi;
			--yi; --xi;
			for (int vi : { yi, xi }) qlst[i].push_back(vi);
		}
	}
	fenwick_tree<ll> lr(m+1);
	vector<pair<int, ll>> res;
	vector<vector<tuple<int, int, ll>>> slst(n);
	repr(i, q) {
		if (qlst[i][0] == 1) {
			lr.add(qlst[i][1], qlst[i][3]);
			lr.add(qlst[i][2], -qlst[i][3]);
		}
		else if (qlst[i][0] == 2) {
			for (auto& pi : slst[qlst[i][1]]) res.emplace_back(get<1>(pi), qlst[i][2]+lr.sum(0,get<0>(pi)+1)-get<2>(pi));
			slst[qlst[i][1]].clear();
		}
		else {
			slst[qlst[i][1]].emplace_back(qlst[i][2], i, lr.sum(0,qlst[i][2]+1));
		}
	}
	rep(i, n) for (auto& pi : slst[i]) res.emplace_back(get<1>(pi), lr.sum(0,get<0>(pi)+1)-get<2>(pi));
	sort(all(res));
	int len = res.size();
	rep(i, len) cout << res[i].second << endl;
	return 0;
}
