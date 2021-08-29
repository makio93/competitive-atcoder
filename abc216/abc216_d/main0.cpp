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

// 本番AC

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> k(m);
	vector<vector<int>> a(m);
	rep(i, m) {
		cin >> k[i];
		a[i] = vector<int>(k[i]);
		rep(j, k[i]) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	vector<int> mid(m);
	unordered_map<int, set<pair<int, int>>> aid;
	map<int, unordered_set<int>> cdata;
	rep(i, m) {
		aid[a[i][0]].emplace(i, 0);
		int cval = aid[a[i][0]].size();
		if (cval > 1) cdata[cval-1].erase(a[i][0]);
		cdata[cval].insert(a[i][0]);
	}
	unordered_set<int> finished;
	bool res = true;
	while ((int)(finished.size()) < n) {
		if (cdata.find(2)==cdata.end() || (cdata.find(2)!=cdata.end()&&cdata[2].empty())) {
			res = false;
			break;
		}
		vector<int> add;
		for (int di : cdata[2]) {
			finished.insert(di);
			for (auto pi : aid[di]) {
				mid[pi.first]++;
				if (mid[pi.first] < k[pi.first]) {
					aid[a[pi.first][mid[pi.first]]].emplace(pi.first, mid[pi.first]);
					add.push_back(a[pi.first][mid[pi.first]]);
				}
			}
			aid.erase(di);
		}
		cdata[2].clear();
		for (int val : add) {
			int cval = aid[val].size();
			if (cval > 1) cdata[cval-1].erase(val);
			cdata[cval].insert(val);
		}
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
