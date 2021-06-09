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

// 自力AC

int main() {
	int n;
	cin >> n;
	map<int, set<int>> item;
	rep(i, n) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		item[ai].insert(i);
		item[bi].insert(i);
	}
	set<int> white, used;
	vector<int> ord;
	rep(i, n) {
		if (item[i].find(i) != item[i].end()) {
			white.insert(i);
			ord.push_back(i);
			item[i].erase(i);
		}
	}
	bool ok = ((int)(ord.size()) == n);
	while (!ok) {
		set<int> add, rem;
		for (int wi : white) {
			if (!item[wi].empty()) {
				for (int it2 : item[wi]) {
					if (used.find(it2)==used.end() && add.find(it2)==add.end() && white.find(it2)==white.end()) {
						add.insert(it2);
						ord.push_back(it2);
					}
				}
			}
			rem.insert(wi);
			used.insert(wi);
		}
		for (auto si : add) white.insert(si);
		for (auto si : rem) white.erase(si);
		if ((int)(ord.size()) >= n) ok = true;
		if (white.empty()) break;
	}
	if (ok) {
		reverse(all(ord));
		rep(i, n) cout << (ord[i]+1) << endl;
	}
	else cout << -1 << endl;
	return 0;
}
