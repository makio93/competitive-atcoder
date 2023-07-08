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
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<string> res(n, string(n, '.'));
	rep3(i, 1, n-1) rep3(j, 1, n-1) res[i][j] = s[i][j];
	rep(i, n-1) res[0][i+1] = s[0][i];
	rep(i, n-1) res[i+1][n-1] = s[i][n-1];
	rep3(i, 1, n) res[n-1][i-1] = s[n-1][i];
	rep3(i, 1, n) res[i-1][0] = s[i][0];
	rep(i, n) cout << res[i] << endl;
	return 0;
}
