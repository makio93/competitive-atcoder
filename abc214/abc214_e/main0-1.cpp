// 本番解答1,TLE

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

int main() {
	int t;
	cin >> t;
	rep(i0, t) {
		int n;
		cin >> n;
		vector<int> l(n), r(n);
		rep(i, n) cin >> l[i] >> r[i];
		vector<pair<int, int>> rl(n);
		rep(i, n) rl[i] = { r[i], l[i] };
		sort(all(rl));
		set<int> ball;
		bool ok = true;
		for (int i=0; i<n; ++i) {
			auto litr = ball.lower_bound(rl[i].second), ritr = ball.lower_bound(rl[i].first+1);
			int d = distance(litr, ritr);
			if (d >= rl[i].first-rl[i].second+1) {
				ok = false;
				break;
			}
			if (ball.find(rl[i].second) == ball.end()) ball.insert(rl[i].second);
			else {
				while ((*litr)+1 <= rl[i].first) {
					if ((*next(litr)) != (*litr)+1) {
						ball.insert((*litr)+1);
						break;
					}
					++litr;
				}
			}
		}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
