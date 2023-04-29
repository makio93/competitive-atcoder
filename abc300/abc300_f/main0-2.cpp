// 自力AC2

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
	int n, m;
	ll k;
	string s;
	cin >> n >> m >> k >> s;
	int xcnt = count(all(s), 'x');
	if (k == (ll)xcnt*m) {
		cout << ((ll)n*m) << endl;
		return 0;
	}
	vector<int> xids;
	ll res = 0;
	if (m == 1) {
		xids.push_back(-1);
		rep(i, n) if (s[i] == 'x') xids.push_back(i);
		xids.push_back(n);
		int xlen = xids.size();
		rep(i, xlen) {
			int ri = min(xlen-1, (int)(i+k+1));
			res = max(res, (ll)(xids[ri]-xids[i]-1));
		}
		cout << res << endl;
		return 0;
	}
	ll aval = k / xcnt, bval = k % xcnt;
	string t = s + s;
	rep(i, n*2) if (t[i] == 'x') xids.push_back(i);
	int xlen = xids.size();
	rep(i, xlen) {
		int ri = min(xlen-1, (int)(i+bval+1));
		if (xids[ri]>=n && xids[i]<n) res = max(res, (xids[ri]-xids[i]-1)+min((ll)(m-2),aval)*n);
		else res = max(res, (xids[ri]-xids[i]-1)+aval*n);
	}
	res = max(res, xids[bval]+aval*n);
	res = max(res, n*2-1-xids[xlen-1-bval]+aval*n);
	cout << res << endl;
	return 0;
}
