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

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<map<int, int>> ab(n);
	vector<vector<int>> bus(m);
	map<int, int> sche;
	rep(i, m) {
		int ai, bi, si, ti;
		cin >> ai >> bi >> si >> ti;
		--ai; --bi;
		ab[ai][si] = i;
		bus[i] = { ai, bi, si, ti };
		sche[si] = i;
	}
	vector<map<int, int>> yx(n);
	vector<int> query(q);
	rep(i, q) {
		int xi, yi, zi;
		cin >> xi >> yi >> zi;
		--yi;
		yx[yi][xi] = i;
		query[i] = zi;
	}
	vector<bool> visited(m);
	vector<vector<int>> ans(q);
	for (auto pi : sche) {
		int si = pi.first, qi = pi.second;
		if (visited[qi]) continue;
		set<int> stock;
		int tm = bus[qi][2], plc = bus[qi][0];
		while (1) {
			auto itr = yx[plc].lower_bound(tm);
			
		}
	}
	return 0;
}
