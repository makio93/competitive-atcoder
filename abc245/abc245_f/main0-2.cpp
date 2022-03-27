// 本番2,WA

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
	int n, m;
	cin >> n >> m;
	scc_graph g(n);
	dsu di(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g.add_edge(vi, ui);
		di.merge(ui, vi);
	}
	auto lst = g.scc();
	int len = lst.size();
	int cnt = 0;
	unordered_set<int> used;
	rep(i, len) {
		if ((int)(lst[i].size()) > 1) {
			used.insert(di.leader(lst[i].front()));
			continue;
		}
		else {
			if (used.find(di.leader(lst[i].front())) == used.end()) cnt += lst[i].size();
		}
	}
	cout << (n-cnt) << endl;
	return 0;
}
