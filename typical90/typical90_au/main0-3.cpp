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

// 自力で作成してみたその2、TLE

int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	const string tar = "RGB";
	vector<string> okstr(3, string(n, 'N'));
	rep(i, 3) rep(j, n) rep(i2, 3) {
		if (s[j] == tar[i]) okstr[i][j] = tar[i];
		else { rep(j2, 3) if (s[j]!=tar[j2] && tar[i]!=tar[j2]) { okstr[i][j] = tar[j2]; break; } }
	}
	int res = 0;
	rep3r(l, -n+1, n) {
		bool ok = false;
		int l2 = max(l, 0), r2 = min(l+n, n), len = r2 - l2;
		rep(j, 3) {
			if (okstr[j].substr(l2,len) == t.substr(l2-l,len)) ok = true;
			if (ok) break;
		}
		if (ok) ++res;
	}
	cout << res << endl;
	return 0;
}
