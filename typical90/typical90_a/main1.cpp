// 解説と実装を見て実装、AC

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
	int lval = -1, rval = l+1;
	while (rval-lval > 1) {
		int cval = lval + (rval-lval) / 2;
		int nlen = 0, kcnt = 0;
		rep(i, n+1) {
			nlen += b[i];
			if (i<n && nlen>=cval) {
				++kcnt;
				nlen = 0;
			}
			if (i==n && nlen<cval) --kcnt;
		}
		if (kcnt < k) rval = cval;
		else lval = cval;
	}
	cout << lval << endl;
	return 0;
}
