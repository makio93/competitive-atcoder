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
	int n;
	cin >> n;
	vector<int> ng(3);
	rep(i, 3) cin >> ng[i];
	vector<int> dp(n+1, INF);
	if (find(all(ng), n) == ng.end()) dp[n] = 0;
	rep3r(i, 1, n+1) {
		if (dp[i] == INF) continue;
		rep3(j, 1, 4) {
			if (i-j < 0) break;
			if (find(all(ng), i-j) != ng.end()) continue;
			dp[i-j] = min(dp[i-j], dp[i]+1);
		}
	}
	if (dp[0]!=INF && dp[0]<=100) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
