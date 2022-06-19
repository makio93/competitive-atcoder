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
	int n;
	cin >> n;
	vector<vector<int>> x(n, vector<int>(n));
	rep(i, n) rep(j, n) x[i][j] = i * n + j + 1;
	rep3(i, 1, n-1) for (int j=1; j+1<n; j+=2) swap(x[i][j], x[i][j+1]);
	rep(i, n) rep(j, n) cout << x[i][j] << (j<n-1?' ':'\n');
	return 0;
}
