// 自力AC

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
	int h, w, n;
	cin >> h >> w >> n;
	vector<vector<int>> g(h, vector<int>(w)), s(h+1, vector<int>(w+1));
	rep(i, n) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai][bi]++;
	}
	rep(i, h) rep(j, w) s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + g[i][j];
	ll res = 0;
	for (int i=1; i<=h; ++i) for (int j=1; j<=w; ++j) if (g[i-1][j-1] == 0) {
		int li = 0, ri = min(h-i+1, w-j+1);
		while (ri-li > 1) {
			int ci = li + (ri-li) / 2;
			if (s[i+ci][j+ci]-s[i-1][j+ci]-s[i+ci][j-1]+s[i-1][j-1] == 0) li = ci;
			else ri = ci;
		}
		res += li + 1;
	}
	cout << res << endl;
	return 0;
}
