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
	vector<string> s(10);
	rep(i, 10) cin >> s[i];
	int a = 10, b = -1, c = 10, d = -1;
	rep(i, 10) if (count(all(s[i]), '#') > 0) {
		a = min(a, i);
		b = max(b, i);
		if (d == -1) {
			rep(j, 10) if (s[i][j] == '#') {
				c = min(c, j);
				d = max(d, j);
			}
		}
	}
	cout << (a+1) << ' ' << (b+1) << endl;
	cout << (c+1) << ' ' << (d+1) << endl;
	return 0;
}
