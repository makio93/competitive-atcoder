// 自力AC

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
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int rcnt = 0, bcnt = 0;
	rep(i, n) rep(j, n) {
		if (s[i][j] == 'R') ++rcnt;
		else if (s[i][j] == 'B') ++bcnt;
	}
	if (rcnt > bcnt) cout << "TAKAHASHI" << endl;
	else if (bcnt > rcnt) cout << "AOKI" << endl;
	else cout << "DRAW" << endl;
	return 0;
}
