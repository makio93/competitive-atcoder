// 本番AC

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

int main() {
	int n;
	cin >> n;
	vector<string> s(n), t(n);
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];
	vector<string> ori = s;
	bool ok = false;
	int tly = n, tlx = n, tdy = 0, tdx = 0;
	rep(i, n) rep(j, n) if (t[i][j] == '#') {
		tly = min(tly, i); tlx = min(tlx, j);
		tdy = max(tdy, i); tdx = max(tdx, j);
	}
	rep(i, 4) {
		if (i > 0) {
			vector<string> nori(n, string(n, '.'));
			rep(i2, n) rep(j2, n) nori[i2][j2] = ori[j2][n-i2-1];
			swap(ori, nori);
		}
		int sly = n, slx = n, sdy = 0, sdx = 0;
		rep(i2, n) rep(j2, n) if (ori[i2][j2] == '#') {
			sly = min(sly, i2); slx = min(slx, j2);
			sdy = max(sdy, i2); sdx = max(sdx, j2);
		}
		if (sdy-sly==tdy-tly && sdx-slx==tdx-tlx) {
			bool ok2 = true;
			int dy = sdy - sly + 1, dx = sdx - slx + 1;
			rep(i2, dy) if (ori[sly+i2].substr(slx,dx) != t[tly+i2].substr(tlx,dx)) ok2 = false;
			if (ok2) { ok = true; break; }
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
