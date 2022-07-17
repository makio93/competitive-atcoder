// 本番AC

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
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	map<int, int> mids;
	unordered_map<int, vector<int>> mdata;
	int nid = 0;
	vector<int> ans(n, -1);
	rep(i, n) {
		auto itr = mids.lower_bound(p[i]);
		if (itr == mids.end()) {
			mids[p[i]] = nid;
			mdata[nid].push_back(p[i]);
			++nid;
		}
		else {
			mids[p[i]] = itr->second;
			mids.erase(itr->first);
			mdata[mids[p[i]]].push_back(p[i]);
		}
		if ((int)(mdata[mids[p[i]]].size()) >= k) {
			for (int val : mdata[mids[p[i]]]) ans[val] = i + 1;
			mdata.erase(mids[p[i]]);
			mids.erase(p[i]);
		}
	}
	rep(i, n) cout << ans[i] << endl;
	return 0;
}
