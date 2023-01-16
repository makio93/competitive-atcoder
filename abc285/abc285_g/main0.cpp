// 自力WA

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
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	vector<vector<vector<bool>>> dp(h, vector<vector<bool>>(w, vector<bool>(5)));
	rep(i, h) rep(j, w) {
		if (c[i][j]=='?' || c[i][j]=='1') {
			bool ok1 = false, ok2 = false;
			if (i-1 < 0) ok1 = true;
			else {
				for (const int id : vector<int>({ 0, 1, 2, 4 })) if (dp[i-1][j][id]) {
					ok1 = true;
					break;
				}
			}
			if (j-1 < 0) ok2 = true;
			else {
				for (const int id : vector<int>({ 0, 1, 4 })) if (dp[i][j-1][id]) {
					ok2 = true;
					break;
				}
			}
			dp[i][j][0] = (ok1 && ok2);
		}
		if (c[i][j]=='?' || c[i][j]=='2') {
			bool ok = true;
			if (i-1<0 || !dp[i-1][j][3]) ok = false;
			if (ok && j-1>=0) {
				ok = false;
				for (const int id : vector<int>({ 0, 1, 4 })) if (dp[i][j-1][id]) {
					ok = true;
					break;
				}
			}
			dp[i][j][1] = ok;
			ok = true;
			if (j+1>=w || c[i][j+1]=='1') ok = false;
			if (ok && i-1>=0) {
				ok = false;
				for (const int id : vector<int>({ 0, 1, 2, 4 })) if (dp[i-1][j][id]) {
					ok = true;
					break;
				}
			}
			if (ok && j-1>=0) {
				ok = false;
				for (const int id : vector<int>({ 0, 1, 4 })) if (dp[i][j-1][id]) {
					ok = true;
					break;
				}
			}
			dp[i][j][2] = ok;
			ok = true;
			if (i+1>=h || c[i+1][j]=='1') ok = false;
			if (ok && i-1>=0) {
				ok = false;
				for (const int id : vector<int>({ 0, 1, 2, 4 })) if (dp[i-1][j][id]) {
					ok = true;
					break;
				}
			}
			if (ok && j-1>=0) {
				ok = false;
				for (const int id : vector<int>({ 0, 1, 4 })) if (dp[i][j-1][id]) {
					ok = true;
					break;
				}
			}
			dp[i][j][3] = ok;
			ok = true;
			if (j-1<0 || !dp[i][j-1][2]) ok = false;
			if (ok && i-1>=0) {
				ok = false;
				for (const int id : vector<int>({ 0, 1, 2, 4 })) if (dp[i-1][j][id]) {
					ok = true;
					break;
				}
			}
			dp[i][j][4] = ok;
		}
	}
	bool res = false;
	for (const int id : vector<int>({ 0, 1, 4 })) res = (res || dp[h-1][w-1][id]);
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
