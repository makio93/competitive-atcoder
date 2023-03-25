// バチャ本番,自力AC

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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> l(n), r(n);
		rep(i, n) cin >> l[i] >> r[i];
		map<int, set<pair<int, int>>> lrlst;
		rep(i, n) {
			lrlst[l[i]].emplace(1, i);
			lrlst[r[i]].emplace(2, i);
		}
		set<pair<int, int>> rbi;
		int bcnt = 0, id = 1;
		bool ok = true;
		while (bcnt < n) {
			if (lrlst.find(id) == lrlst.end()) {
				if (rbi.empty()) {
					id = lrlst.lower_bound(id)->first;
					continue;
				}
				rbi.erase(rbi.begin());
				++bcnt; ++id;
			}
			else {
				auto itr = lrlst[id].begin();
				while (itr!=lrlst[id].end() && itr->first==1) {
					rbi.emplace(r[itr->second], itr->second);
					++itr;
				}
				if (!rbi.empty()) {
					rbi.erase(rbi.begin());
					++bcnt;
				}
				while (itr != lrlst[id].end()) {
					if (rbi.find({ r[itr->second], itr->second }) != rbi.end()) {
						ok = false;
						break;
					}
					++itr;
				}
				if (!ok) break;
				++id;
			}
		}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
