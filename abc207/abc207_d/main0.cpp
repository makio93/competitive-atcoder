#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番実装、WA

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	rep(i, n) cin >> a[i] >> b[i];
	rep(i, n) cin >> c[i] >> d[i];
	if (n == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	vector<vector<int>> sdist(n, vector<int>(n)), tdist(n, vector<int>(n));
	rep(i, n) rep(j, n) {
		sdist[i][j] = (a[i]-a[j]) * (a[i]-a[j]) + (b[i]-b[j]) * (b[i]-b[j]);
		tdist[i][j] = (c[i]-c[j]) * (c[i]-c[j]) + (d[i]-d[j]) * (d[i]-d[j]);
	}
	vector<pair<vector<pair<int, int>>, int>> sdl1(n);
	vector<pair<vector<pair<int, int>>, int>> tdl1(n);
	rep(i, n) {
		rep(j, n) sdl1[i].first.emplace_back(sdist[i][j], j);
		rep(j, n) tdl1[i].first.emplace_back(tdist[i][j], j);
		sdl1[i].second = i;
		tdl1[i].second = i;
		sort(all(sdl1[i].first));
		sort(all(tdl1[i].first));
	}
	sort(all(sdl1));
	sort(all(tdl1));
	bool ok1 = true;
	rep(i, n) rep(j, n) if (sdl1[i].first[j].first != tdl1[i].first[j].first) ok1 = false;
	if (!ok1) {
		cout << "No" << endl;
		return 0;
	}
	else {
		int sid = sdl1[0].second, tid = tdl1[0].second;
		int sid0 = sdl1[0].first[0].second, tid0 = tdl1[0].first[0].second;
		int sval0 = (a[sid]-a[sid0]) * (d[tid]-d[tid0]) - (c[tid]-c[tid0]) * (b[sid]-b[sid0]);
		bool ok2 = true;
		rep3(i, 1, n) {
			int sid2 = sdl1[0].first[i].second, tid2 = tdl1[0].first[i].second;
			int sval = (a[sid]-a[sid2]) * (d[tid]-d[tid2]) - (c[tid]-c[tid2]) * (b[sid]-b[sid2]);
			if (sval != sval0) ok2 = false;
		}
		if (ok2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
