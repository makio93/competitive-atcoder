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

// 自力解答、WA

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> rl(m);
	rep(i, m) {
		cin >> rl[i].second >> rl[i].first;
		rl[i].first--; rl[i].second--;
	}
	sort(all(rl));
	map<int, vector<int>> lr;
	rep(i, m) lr[rl[i].second].push_back(rl[i].first);
	ll res = 0;
	for (auto p : lr) {
		int li = p.first; auto ra = p.second;
		for (int p2 : ra) {
			auto litr = lr.upper_bound(li), ritr = lr.lower_bound(p2);
			for (auto itr2=litr; itr2!=ritr; ++itr2) {
				auto tar = itr2->second;
				res += (int)(tar.size()) - (int)(upper_bound(all(tar), p2) - tar.begin());
			}
		}
	}
	cout << res << endl;
	return 0;
}
