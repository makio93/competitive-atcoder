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
	vector<int> p(n);
	vector<vector<bool>> f(n, vector<bool>(m));
	rep(i, n) {
		int ci;
		cin >> p[i] >> ci;
		rep(j, ci) {
			int fi;
			cin >> fi;
			--fi;
			f[i][fi] = true;
		}
	}
	bool res = false;
	rep(i, n) rep(j, n) {
		if (p[j] > p[i]) continue;
		bool upper = false, ng = false;
		rep(i2, m) {
			if (f[i][i2] && !f[j][i2]) ng = true;
			if (!f[i][i2] && f[j][i2]) upper = true;
		}
		if (ng) continue;
		if (p[j] < p[i] || (p[j] == p[i] && upper)) res = true;
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
