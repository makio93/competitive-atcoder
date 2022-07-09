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
	string s, t;
	cin >> s >> t;
	auto to_run = [](string& str) -> vector<pair<char, int>> {
		int n = str.length();
		vector<pair<char, int>> rlst;
		rlst.emplace_back(str[0], 1);
		rep3(i, 1, n) {
			if (rlst.back().first == str[i]) rlst.back().second++;
			else rlst.emplace_back(str[i], 1);
		}
		return rlst;
	};
	auto slst = to_run(s), tlst = to_run(t);
	int n = slst.size(), m = tlst.size();
	if (n != m) {
		cout << "No" << endl;
		return 0;
	}
	bool ok = true;
	rep(i, n) {
		if (slst[i].first != tlst[i].first) {
			ok = false;
			break;
		}
		if (slst[i].second == 1) {
			if (tlst[i].second > 1) {
				ok = false;
				break;
			}
		}
		else {
			if (tlst[i].second < slst[i].second) {
				ok = false;
				break;
			}
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
