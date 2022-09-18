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

using mint = modint998244353;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	rep(i, q) {
		int ai, bi, ci, di;
		cin >> ai >> bi >> ci >> di;
		mint res = 0;
		if ((ai+ci)%2 == 0) {
			{
				mint aval = (mint)(ai-1) * m + ci, rlen = ((di-ci+1) + 1) / 2;
				mint rsum = (aval + (aval + (rlen-1) * 2)) * rlen / 2;
				mint clen = ((bi-ai+1) + 1) / 2, dval = rlen * 2 * m;
				mint csum = (rsum + (rsum + (clen-1) * dval)) * clen / 2;
				res += csum;
			}
			if (ai+1<=bi && ci+1<=di) {
				mint aval = (mint)(ai) * m + ci + 1, rlen = ((di-ci) + 1) / 2;
				mint rsum = (aval + (aval + (rlen-1) * 2)) * rlen / 2;
				mint clen = ((bi-ai) + 1) / 2, dval = rlen * 2 * m;
				mint csum = (rsum + (rsum + (clen-1) * dval)) * clen / 2;
				res += csum;
			}
		}
		else {
			if (ci+1 <= di) {
				mint aval = (mint)(ai-1) * m + ci + 1, rlen = ((di-ci) + 1) / 2;
				mint rsum = (aval + (aval + (rlen-1) * 2)) * rlen / 2;
				mint clen = ((bi-ai+1) + 1) / 2, dval = rlen * 2 * m;
				mint csum = (rsum + (rsum + (clen-1) * dval)) * clen / 2;
				res += csum;
			}
			if (ai+1 <= bi) {
				mint aval = (mint)(ai) * m + ci, rlen = ((di-ci+1) + 1) / 2;
				mint rsum = (aval + (aval + (rlen-1) * 2)) * rlen / 2;
				mint clen = ((bi-ai) + 1) / 2, dval = rlen * 2 * m;
				mint csum = (rsum + (rsum + (clen-1) * dval)) * clen / 2;
				res += csum;
			}
		}
		cout << res.val() << endl;
	}
	return 0;
}
