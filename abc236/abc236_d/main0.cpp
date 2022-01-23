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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(2*n, vector<int>(2*n));
	rep(i, 2*n-1) rep3(j, i+1, 2*n) {
		int ai;
		cin >> ai;
		a[i][j] = a[j][i] = ai;
	}
	int res = 0;
	vector<bool> choosed(2*n);
	function<void(int,int)> dfs = [&](int di, int xval) -> void {
		if (di == n) {
			res = max(res, xval);
			return;
		}
		else {
			rep(i, 2*n) {
				if (choosed[i]) continue;
				choosed[i] = true;
				rep3(j, i+1, 2*n) {
					if (choosed[j]) continue;
					choosed[j] = true;
					dfs(di+1, xval^a[i][j]);
					choosed[j] = false;
				}
				choosed[i] = false;
				break;
			}
		}
	};
	dfs(0, 0);
	cout << res << endl;
	return 0;
}
