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

// 本番WA

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> l(n), r(n);
	rep(i, n) cin >> l[i] >> r[i];
	map<int, map<int, int>> wlst;
	set<int> uid;
	rep(i, n) {
		wlst[l[i]][1] = i;
		wlst[r[i]][2] = i;
	}
	int res = 0;
	set<int> cid;
	auto itr = wlst.begin();
	while (itr != wlst.end()) {
		while (itr != wlst.end()) {
			bool fin = false;
			for (auto pi : itr->second) if (uid.find(pi.second) == uid.end()) {
				if (pi.first == 1) cid.insert(pi.second);
				else fin = true;
			}
			if (fin) break;
			++itr;
		}
		if (itr == wlst.end()) {
			if (!cid.empty()) {
				++res;
				for (int id : cid) uid.insert(id);
				cid.clear();
			}
			break;
		}
		int lpos = itr->first, rpos = lpos + d - 1;
		auto titr = next(itr);
		while (titr!=wlst.end() && titr->first<=rpos) {
			for (auto pi : titr->second) if (uid.find(pi.second) == uid.end()) {
				cid.insert(pi.second);
			}
			++titr;
		}
		if (!cid.empty()) {
			++res;
			for (int id : cid) uid.insert(id);
			cid.clear();
		}
		itr = titr;
	}
	cout << res << endl;
	return 0;
}
