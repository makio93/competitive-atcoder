// ヒント有,自力AC

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
	vector<set<int>> stot(s);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
		stot[u[i]].insert(v[i]-s);
	}
	vector<int> res;
	unordered_map<int, int> tps;
	rep(i, s) {
		for (auto itr=stot[i].begin(); itr!=stot[i].end(); ++itr) {
			for (auto ritr=next(itr); ritr!=stot[i].end(); ++ritr) {
				int tval = *itr * t + *ritr;
				if (tps.find(tval) != tps.end()) {
					res.push_back(i);
					res.push_back(tps[tval]);
					res.push_back(s+tval%t);
					res.push_back(s+tval/t);
					break;
				}
				tps[tval] = i;
			}
			if (!res.empty()) break;
		}
		if (!res.empty()) break;
	}
	if (!res.empty()) rep(i, 4) cout << (res[i]+1) << (i<3?' ':'\n');
	else cout << -1 << endl;
	return 0;
}
