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
	int n, t;
	cin >> n >> t;
	vector<int> c(n), r(n);
	rep(i, n) cin >> c[i];
	rep(i, n) cin >> r[i];
	pair<int, int> mval = { -1, -1 };
	if (count(all(c), t) > 0) {
		rep(i, n) if (c[i] == t) mval = max(mval, { r[i], i });
	}
	else {
		rep(i, n) if (c[i] == c[0]) mval = max(mval, { r[i], i });
	}
	cout << (mval.second+1) << endl;
	return 0;
}
