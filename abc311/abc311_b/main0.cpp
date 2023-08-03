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
	int n, d;
	cin >> n >> d;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int res = 0, val = 0;
	rep(i, d) {
		bool ok = true;
		rep(j, n) if (s[j][i] == 'x') ok = false;
		if (ok) ++val;
		else val = 0;
		res = max(res, val);
	}
	cout << res << endl;
	return 0;
}
