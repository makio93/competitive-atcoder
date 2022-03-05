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

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> wins(n);
	set<pair<int, int>> eds;
	rep(i, n) rep(j, i) eds.emplace(j, i);
	rep(i, m) {
		int wi, li;
		cin >> wi >> li;
		--wi; --li;
		wins[wi]++;
		if (wi > li) swap(wi, li);
		eds.erase({wi, li});
	}
	int elen = eds.size();
	vector<int> aset;
	rep(i, n) {
		int sid = elen + n, tid = sid + 1;
		mf_graph<int> g(tid+1);
		int eid = 0, wcnt = 0;
		for (auto [ai, bi] : eds) {
			if (ai==i || bi==i) {
				g.add_edge(sid, eid, 1);
				g.add_edge(eid, elen+i, 1);
				++wcnt;
			}
			else {
				g.add_edge(sid, eid, 1);
				g.add_edge(eid, elen+ai, 1);
				g.add_edge(eid, elen+bi, 1);
			}
			++eid;
		}
		bool ok = true;
		rep(j, n) {
			if (j == i) g.add_edge(elen+j, tid, wcnt);
			else {
				int tval = wins[i] + wcnt - 1 - wins[j];
				if (tval < 0) {
					ok = false;
					break;
				}
				g.add_edge(elen+j, tid, tval);
			}
		}
		if (!ok) continue;
		if (g.flow(sid, tid) == elen) aset.push_back(i+1);
	}
	int alen = aset.size();
	if (alen == 0) cout << endl;
	else rep(i, alen) printf("%d%c", aset[i], (i<alen-1?' ':'\n'));
	return 0;
}
