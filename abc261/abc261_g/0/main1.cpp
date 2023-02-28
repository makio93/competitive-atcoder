// 解説AC

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
	string s, t;
	int k;
	cin >> s >> t >> k;
	int m = s.length(), n = t.length();
	vector<string> c(k), a(k);
	rep(i, k) cin >> c[i] >> a[i];
	int alen = 0;
	rep(i, k) alen = max(alen, (int)(a[i].length()));
	vector<vector<vector<int>>> dp0(n, vector<vector<int>>(n, vector<int>(26, INF))), dp1;
	vector<vector<int>> atoc(26);
	rep(i, k) if ((int)(a[i].length()) == 1) atoc[a[i][0]-'a'].push_back(c[i][0]-'a');
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	repr(i, n) {
		dp1.assign(n, vector<vector<int>>(k, vector<int>(alen, INF)));
		rep3(j, i, n) {
			if (j == i) {
				pq.emplace(0, t[j]-'a');
				dp0[i][j][t[j]-'a'] = 0;
				for (int ci : atoc[t[j]-'a']) {
					if (dp0[i][j][ci] > 1) {
						pq.emplace(1, ci);
						dp0[i][j][ci] = 1;
					}
				}
			}
			else {
				rep(i2, k) {
					rep3(j2, 1, a[i2].length()) rep3(k2, i, j) if (dp1[k2][i2][j2-1]!=INF && dp0[k2+1][j][a[i2][j2]-'a']!=INF) {
						dp1[j][i2][j2] = min(dp1[j][i2][j2], dp1[k2][i2][j2-1]+dp0[k2+1][j][a[i2][j2]-'a']);
					}
					if (dp0[i][j][c[i2][0]-'a'] > dp1[j][i2][a[i2].length()-1]+1) {
						dp0[i][j][c[i2][0]-'a'] = dp1[j][i2][a[i2].length()-1] + 1;
						pq.emplace(dp0[i][j][c[i2][0]-'a'], c[i2][0]-'a');
					}
				}
			}
			while (!pq.empty()) {
				auto pi = pq.top(); pq.pop();
				int di = pi.first, ci = pi.second, ndi = di + 1;
				if (dp0[i][j][ci] != di) continue;
				for (int ti : atoc[ci]) if (dp0[i][j][ti] > ndi) {
					dp0[i][j][ti] = ndi;
					pq.emplace(ndi, ti);
				}
			}
			rep(i2, k) dp1[j][i2][0] = dp0[i][j][a[i2][0]-'a'];
		}
	}
	vector<vector<int>> dpa(n+1, vector<int>(m+1, INF));
	dpa[0][0] = 0;
	rep(i, n) {
		if (i == 0) dp0[0][i][t[i]-'a'] = 0;
		else {
			rep3(j, 2, m+1) rep3(i2, 1, i+1) if (dpa[i2][j-1]!=INF && dp0[i2][i][s[j-1]-'a']!=INF) {
				dpa[i+1][j] = min(dpa[i+1][j], dpa[i2][j-1]+dp0[i2][i][s[j-1]-'a']);
			}
		}
		dpa[i+1][1] = dp0[0][i][s[0]-'a'];
	}
	if (dpa[n][m] == INF) cout << -1 << endl;
	else cout << dpa[n][m] << endl;
	return 0;
}
