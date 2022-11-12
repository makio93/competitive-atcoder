// 本番WA

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
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	if (h <= 2) {
		int umx = *max_element(all(a[0])), umn = INF;
		int dmx = *max_element(all(a[1])), dmn = INF;
		rep(i, w) if (a[0][i] != 0) umn = min(umn, a[0][i]);
		rep(i, w) if (a[1][i] != 0) dmn = min(dmn, a[1][i]);
		if (umx <= dmn || dmx <= umn) {
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
		return 0;
	}
	vector<int> ord(w);
	iota(all(ord), 0);
	bool ok = true;
	sort(all(ord), [&](int li, int ri) -> bool {
		if (!ok) return li < ri;
		int tid = -1;
		bool zl = false, zr = false;
		rep(i, h) {
			if (a[i][li] != 0) zl = true;
			if (a[i][ri] != 0) zr = true;
			if (a[i][li]==0 || a[i][ri]==0 || a[i][li]==a[i][ri]) continue;
			if (tid == -1) tid = i;
			else if ((a[i][li]<a[i][ri]) != (a[tid][li]<a[tid][ri])) {
				ok = false;
				return li < ri;
			}
		}
		if (tid == -1) {
			return zl < zr;
		}
		else return a[tid][li] < a[tid][ri];
	});
	if (!ok) {
		cout << "No" << endl;
		return 0;
	}
	vector<vector<int>> b(h, vector<int>(w));
	rep(i, h) rep(j, w) b[i][j] = a[i][ord[j]];
	vector<pair<int, int>> lr;
	rep(i, h) {
		if (b[i] == vector<int>(w, 0)) continue;
		int lv = -1, rv = -1;
		rep(j, w) if (b[i][j] != 0) {
			lv = b[i][j];
			break;
		}
		repr(j, w) if (b[i][j] != 0) {
			rv = b[i][j];
			break;
		}
		lr.emplace_back(lv, rv);
	}
	if (!lr.empty()) {
		sort(all(lr));
		int m = lr.size();
		rep(i, m-1) if (lr[i].second > lr[i+1].first) {
			ok = false;
			break;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
