// 本番TLE

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
	int s, t, m;
	cin >> s >> t >> m;
	vector<int> u(m), v(m);
	vector<unordered_set<int>> vtos(t);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
		vtos[v[i]-s].insert(u[i]);
	}
	vector<int> ord(t);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool {
		return vtos[li].size() > vtos[ri].size();
	});
	vector<int> ans;
	bool ok = false;
	rep(i, t) {
		rep3(j, i+1, t) {
			vector<int> tmp;
			for (int vid : vtos[ord[j]]) if (vtos[ord[i]].find(vid) != vtos[ord[i]].end()) {
				tmp.push_back(vid);
				if ((int)(tmp.size()) >= 2) break;
			}
			if ((int)(tmp.size()) == 2) {
				ok = true;
				ans.push_back(tmp[0]);
				ans.push_back(tmp[1]);
				ans.push_back(s+ord[i]);
				ans.push_back(s+ord[j]);
				break;
			}
		}
		if (ok) break;
	}
	if (ok) {
		rep(i, 4) cout << (ans[i]+1) << (i<3?' ':'\n');
	}
	else cout << -1 << endl;
	return 0;
}
