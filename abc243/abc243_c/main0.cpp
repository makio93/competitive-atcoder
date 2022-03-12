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

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	string s;
	cin >> s;
	unordered_map<int, vector<pair<int, char>>> xlst;
	rep(i, n) xlst[y[i]].emplace_back(x[i], s[i]);
	bool yes = false;
	for (auto &pi : xlst) {
		sort(all(pi.second));
		bool right = false;
		rep(i, (int)(pi.second.size())) {
			if (pi.second[i].second=='R' && !right) right = true;
			else if (pi.second[i].second=='L' && right) {
				yes = true;
				break;
			} 
		}
		if (yes) break;
	}
	if (yes) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
