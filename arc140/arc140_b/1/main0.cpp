// 学習1回目,バチャ,自力AC

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
	int n;
	string s;
	cin >> n >> s;
	vector<pair<char, int>> runs;
	runs.emplace_back(s[0], 1);
	rep3(i, 1, n) {
		if (s[i] == runs.back().first) runs.back().second++;
		else runs.emplace_back(s[i], 1);
	}
	multiset<int> ast;
	int m = runs.size();
	rep(i, m) if (runs[i].first=='R' && runs[i].second==1) {
		int val = INF;
		if (i-1>=0 && runs[i-1].first=='A') val = min(val, runs[i-1].second);
		else val = min(val, 0);
		if (i+1<m && runs[i+1].first=='C') val = min(val, runs[i+1].second);
		else val = min(val, 0);
		if (val > 0) ast.insert(val);
	}
	int res = 0;
	while (!ast.empty()) {
		int ti = *prev(ast.end());
		ast.erase(prev(ast.end()));
		++res;
		--ti;
		if (ti >= 1) ast.insert(ti);
		if (ast.empty()) break;
		ast.erase(ast.begin());
		++res;
	}
	cout << res << endl;
	return 0;
}
