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

// 本番AC

int main() {
	vector<string> s(2);
	rep(i, 2) cin >> s[i];
	int scnt = 0;
	rep(i, 2) rep(j, 2) if (s[i][j] == '#') ++scnt;
	bool ok = true;
	if (scnt == 2) {
		if (s[0][0]=='#' && s[1][1]=='#') ok = false;
		else if (s[0][1]=='#' && s[1][0]=='#') ok = false;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
