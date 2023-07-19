// 本番TLE2

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
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	int asum = accumulate(all(a), 0);
	map<int, int> dp;
	dp[asum] = 0;
	rep(i, n) {
		int sub = b[i] - a[i];
		if (sub > 0) {
			for (auto itr=dp.rbegin(); itr!=dp.rend(); ++itr) {
				if (dp.find(itr->first+sub) == dp.end()) dp[itr->first+sub] = itr->second + 1;
				else dp[itr->first+sub] = min(dp[itr->first+sub], itr->second+1);
			}
		}
		else if (sub < 0) {
			for (auto itr=dp.begin(); itr!=dp.end(); ++itr) {
				if (dp.find(itr->first+sub) == dp.end()) dp[itr->first+sub] = itr->second + 1;
				else dp[itr->first+sub] = min(dp[itr->first+sub], itr->second+1);
			}
		}
		if ((int)(dp.size()) == m+1) break;
	}
	rep(i, m+1) {
		if (dp.find(i) != dp.end()) cout << dp[i] << endl;
		else cout << -1 << endl;
	}
	return 0;
}
