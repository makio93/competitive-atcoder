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
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<int> ldist(n, INF), rdist(n, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	ldist[0] = 0;
	pq.emplace(0, 0);
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		int vi = pi.second, di = pi.first;
		if (di != ldist[vi]) continue;
		int ndi = di + 1;
		rep(i, m) if (s[vi][i] == '1') {
			int ti = vi + i + 1;
			if (ldist[ti] <= ndi) continue;
			ldist[ti] = ndi;
			pq.emplace(ndi, ti);
		}
	}
	rdist[n-1] = 0;
	pq.emplace(0, n-1);
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		int vi = pi.second, di = pi.first;
		if (di != rdist[vi]) continue;
		int ndi = di + 1;
		rep(i, m) if (vi-1-i>=0 && s[vi-1-i][i]=='1') {
			int ti = vi - 1 - i;
			if (rdist[ti] <= ndi) continue;
			rdist[ti] = ndi;
			pq.emplace(ndi, ti);
		}
	}
	vector<int> res(n, -1);
	rep3(i, 1, n-1) {
		int val = INF;
		rep(j1, m) rep(j2, m) {
			int li = i - 1 - j1, ri = i + 1 + j2;
			if (li<0 || ri>=n || ri-li>m || s[li][ri-li-1]=='0') continue;
			val = min(val, ldist[li]+1+rdist[ri]);
		}
		if (val != INF) res[i] = val;
	}
	rep3(i, 1, n-1) cout << res[i] << (i<n-2?' ':'\n');
	return 0;
}
