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

const string tar = "ABXY";

int main() {
	int n;
	cin >> n;
	string c;
	cin >> c;
	vector<int> dp;
	int res = INF;
	rep(l1, 4) rep(l2, 4) rep(r1, 4) rep(r2, 4) {
		dp.assign(n+1, INF);
		dp[0] = 0;
		rep(i, n) {
			dp[i+1] = min(dp[i+1], dp[i]+1);
			if (i-1 >= 0) {
				if (i-1>=0 && ((c[i-1]==tar[l1]&&c[i]==tar[l2])||(c[i-1]==tar[r1]&&c[i]==tar[r2]))) 
					dp[i+1] = min(dp[i+1],  dp[i-1]+1);
			}
		}
		res = min(res, dp[n]);
	}
	cout << res << endl;
	return 0;
}
