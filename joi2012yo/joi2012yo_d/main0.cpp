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
const int mod = (int)(1e4);

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> ab(n, -1);
	rep(i, k) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		ab[ai] = bi;
	}
	vector<vector<int>> dp(n-1, vector<int>(3*3));
	rep(i, 3) rep(j, 3) if ((ab[0]==-1||ab[0]==i) && (ab[1]==-1||ab[1]==j)) dp[0][i*3+j] = 1;
	rep(i1, n-2) {
		rep(i, 3) rep(j, 3) rep(i2, 3) if ((ab[i1+2]==-1||ab[i1+2]==i2) && (i!=j||j!=i2)) 
			dp[i1+1][j*3+i2] = (dp[i1+1][j*3+i2] + dp[i1][i*3+j]) % mod;
	}
	int res = 0;
	rep(i, 3) rep(j, 3) res = (res + dp[n-2][i*3+j]) % mod;
	cout << res << endl;
	return 0;
}
