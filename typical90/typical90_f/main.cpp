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

// 自力で実装、AC

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	deque<pair<char, int>> run;
	rep3r(i, n-k, n) {
		if (run.empty() || run.back().first!=s[i]) run.emplace_back(s[i], 1);
		else run.back().second++;
	}
	repr(i, n-k) {
		if (run.back().first != s[i]) run.emplace_back(s[i], 1);
		else run.back().second++;
		int id = (run.size()) - 1;
		while (id > 0) {
			if (run[id-1].first < run[id].first) break;
			else --id;
		}
		if (run[id].second > 1) run[id].second--;
		else run.erase(run.begin()+id);
	}
	reverse(all(run));
	string ans;
	for (auto p : run) ans += string(p.second, p.first);
	cout << ans << endl;
	return 0;
}
