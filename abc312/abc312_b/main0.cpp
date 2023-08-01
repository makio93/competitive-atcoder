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
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	function<bool(int, int)> check = [&](int yi, int xi) {
		rep(i, 3) rep(j, 3) if (s[yi+i][xi+j] == '.') return false;
		rep(i, 3) rep(j, 3) if (s[yi+6+i][xi+6+j] == '.') return false;
		rep(i, 4) if (s[yi+3][xi+i] == '#') return false;
		rep(i, 4) if (s[yi+i][xi+3] == '#') return false;
		rep(i, 4) if (s[yi+5][xi+8-i] == '#') return false;
		rep(i, 4) if (s[yi+8-i][xi+5] == '#') return false;
		return true;
	};
	vector<pair<int, int>> res;
	for (int i=0; i+8<n; ++i) for (int j=0; j+8<m; ++j) if (check(i, j)) res.emplace_back(i+1, j+1);
	if (res.empty()) cout << endl;
	else for (const auto [yi, xi] : res) cout << yi << ' ' << xi << endl;
	return 0;
}
