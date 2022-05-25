// 解説AC

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
	vector<int> s(n), t(n), x(n), d(q);
	rep(i, n) cin >> s[i] >> t[i] >> x[i];
	rep(i, q) cin >> d[i];
	vector<tuple<int, int, int>> elst;
	map<int, int> xst;
	rep(i, n) {
		elst.emplace_back(s[i]-x[i], 1, x[i]);
		elst.emplace_back(t[i]-x[i], -1, x[i]);
	}
	sort(all(elst));
	int eid = 0, m = elst.size();
	rep(i, q) {
		while (eid<m && get<0>(elst[eid])<=d[i]) {
			if (get<1>(elst[eid]) == 1) xst[get<2>(elst[eid])]++;
			else xst[get<2>(elst[eid])]--;
			if (xst[get<2>(elst[eid])] == 0) xst.erase(get<2>(elst[eid]));
			++eid;
		}
		if (!xst.empty()) cout << xst.begin()->first << endl;
		else cout << -1 << endl;
	}
	return 0;
}
