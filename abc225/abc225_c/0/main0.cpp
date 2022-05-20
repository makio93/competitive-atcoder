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

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(m));
	rep(i, n) rep(j, m) cin >> b[i][j];
	bool ok = true;
	vector<int> b0(m);
	rep(j, m) b0[j] = b[0][j] % 7;
	rep(j, m-1) {
		if (b0[j]>=1 && b0[j]<=5) { if (b0[j+1]-b0[j] != 1) ok = false; }
		else if (b0[j] == 6) { if (b0[j+1] != 0) ok = false; }
		else if (b0[j] == 0) ok = false;
	}
	if (!ok) {
		cout << "No" << endl;
		return 0;
	}
	rep3(i, 1, n) {
		rep(j, m) if (b[i][j]-b[i-1][j] != 7) ok = false;
		rep(j, m) if (b[i][j]%7 != b0[j]) ok = false;
		if (!ok) break;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
