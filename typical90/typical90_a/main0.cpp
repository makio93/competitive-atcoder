// 自力で実装、WA

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
	int n, l, k;
	cin >> n >> l >> k;
	vector<int> a, b;
	a.push_back(0);
	rep(i, n) {
		int ai;
		cin >> ai;
		a.push_back(ai);
	}
	a.push_back(l);
	rep3(i, 1, n+2) b.push_back(a[i]-a[i-1]);
	int mval = (int)(1e9) + 5;
	for (int bi : b) mval = min(mval, bi);
	int lval = mval, rval = l+1, res = (int)(1e9) + 5;
	while (rval-lval > 1) {
		int cval = (lval+rval) / 2;
		int kcnt = 0, nlen = 0, bsz = b.size();
		res = (int)(1e9) + 5;
		rep(i, bsz) {
			nlen += b[i];
			if (nlen >= cval) {
				if (i < bsz-1) ++kcnt;
				res = min(res, nlen);
				nlen = 0;
			}
		}
		if (kcnt < k) rval = cval;
		else if (kcnt > k) lval = cval+1;
		else lval = cval;
	}
	cout << lval << endl;
	return 0;
}
