// 解説AC2

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
	int cnt = 0;
	rep(i, n) rep(j, n) if ((i+j)%2 == 1) x[i][j] = cnt++ + 1;
	rep(i, n) rep(j, n) if ((i+j)%2 == 0) x[i][j] = cnt++ + 1;
	rep(i, n) rep(j, n) cout << x[i][j] << (j<n-1?' ':'\n');
	return 0;
}
