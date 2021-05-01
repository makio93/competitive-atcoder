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

// 解説を見てから実装、AC

int main() {
	int n, m;
	cin >> n >> m;
	vector<map<int, int>> xy(n);
	rep(i, m) {
		int xi, yi, zi;
		cin >> xi >> yi >> zi;
		--xi; --yi;
		if (xi >= 0) {
			if (xy[xi].find(yi) == xy[xi].end()) xy[xi][yi] = zi;
			else xy[xi][yi] = min(xy[xi][yi], zi);
		}
	}
	map<int, ll> dp;
	dp[0] = 1;
	rep(i, n) {
		map<int, ll> dp2;
		for (auto p : dp) {
			int si = p.first;
			rep(j, n) if (!((si>>j)&1)) {
				int tsi = si | (1<<j);
				bool ok = true;
				if (!xy[i].empty()) {
					for (auto p2 : xy[i]) {
						int cnt = 0;
						rep(j2, n) if (((tsi>>j2)&1) && j2<=p2.first) ++cnt;
						if (cnt > p2.second) {
							ok = false;
							if (!ok) break;
						}
					}
				}
				if (ok) dp2[tsi] += p.second;
			}
		}
		swap(dp, dp2);
	}
	cout << dp[(1<<n)-1] << endl;
	return 0;
}
