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
	vector<vector<int>> a(m, vector<int>(n));
	rep(i, m) rep(j, n) {
		cin >> a[i][j];
		a[i][j]--;
	}
	vector<vector<bool>> used(n, vector<bool>(n));
	rep(i, n) used[i][i] = true;
	rep(i, m) rep(j, n-1) used[a[i][j]][a[i][j+1]] = used[a[i][j+1]][a[i][j]] = true;
	int res = 0;
	rep(i, n) rep3(j, i+1, n) if (!used[i][j]) ++res;
	cout << res << endl;
	return 0;
}
