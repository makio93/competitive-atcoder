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
	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	bool ok = true;
	rep(i, n) rep3(j, i+1, n) {
		if (a[i][j]=='W' && a[j][i]!='L') ok = false;
		if (a[i][j]=='L' && a[j][i]!='W') ok = false;
		if (a[i][j]=='D' && a[j][i]!='D') ok = false;
	}
	if (ok) cout << "correct" << endl;
	else cout << "incorrect" << endl;
	return 0;
}
