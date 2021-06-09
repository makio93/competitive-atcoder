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

// 自力AC

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	cin >> m;
	vector<set<int>> xy(n);
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		xy[xi].insert(yi);
		xy[yi].insert(xi);
	}
	int res = INF;
	vector<int> p(n);
	rep(i, n) p[i] = i;
	do {
		bool ok = true;
		rep(i, n-1) if (xy[p[i]].find(p[i+1]) != xy[p[i]].end()) {
			ok = false;
			break;
		}
		if (!ok) continue;
		int sum = 0;
		rep(i, n) sum += a[p[i]][i];
		res = min(res, sum);
	} while (next_permutation(all(p)));
	if (res != INF) cout << res << endl;
	else cout << -1 << endl;
	return 0;
}
