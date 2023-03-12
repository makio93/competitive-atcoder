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

const long double DINF = 3e18;

int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	vector<int> plst, nlst;
	rep(i, n) {
		if (x[i] > 0) plst.push_back(x[i]);
		else nlst.push_back(x[i]);
	}
	sort(all(plst));
	sort(all(nlst), greater<int>());
	long double lval = DINF, rval = -DINF;
	int plen = plst.size(), nlen = nlst.size();
	if (plen >= 3) {
		rep(i, 4) {
			vector<int> tlst;
			rep(i2, i) tlst.push_back(plst[i2]);
			rep(i2, 3-i) tlst.push_back(plst[plen-1-i2]);
			long double dval = 0.0;
			rep(i2, 3) dval += tlst[i2];
			rep(i2, 3) dval /= tlst[i2];
			lval = min(lval, dval);
			rval = max(rval, dval);
		}
	}
	if (nlen >= 3) {
		rep(i, 4) {
			vector<int> tlst;
			rep(i2, i) tlst.push_back(nlst[i2]);
			rep(i2, 3-i) tlst.push_back(nlst[nlen-1-i2]);
			long double dval = 0.0;
			rep(i2, 3) dval += tlst[i2];
			rep(i2, 3) dval /= tlst[i2];
			lval = min(lval, dval);
			rval = max(rval, dval);
		}
	}
	if (nlen>=2 && plen>=1) {
		rep(i, 3) rep(j, 2) {
			vector<int> tlst;
			rep(i2, i) tlst.push_back(nlst[i2]);
			rep(i2, 2-i) tlst.push_back(nlst[nlen-1-i2]);
			rep(i2, j) tlst.push_back(plst[i2]);
			rep(i2, 1-j) tlst.push_back(plst[plen-1-i2]);
			long double dval = 0.0;
			rep(i2, 3) dval += tlst[i2];
			rep(i2, 3) dval /= tlst[i2];
			lval = min(lval, dval);
			rval = max(rval, dval);
		}
	}
	if (nlen>=1 && plen>=2) {
		rep(i, 3) rep(j, 2) {
			vector<int> tlst;
			rep(i2, i) tlst.push_back(plst[i2]);
			rep(i2, 2-i) tlst.push_back(plst[plen-1-i2]);
			rep(i2, j) tlst.push_back(nlst[i2]);
			rep(i2, 1-j) tlst.push_back(nlst[nlen-1-i2]);
			long double dval = 0.0;
			rep(i2, 3) dval += tlst[i2];
			rep(i2, 3) dval /= tlst[i2];
			lval = min(lval, dval);
			rval = max(rval, dval);
		}
	}
	printf("%.15Lf\n", lval);
	printf("%.15Lf\n", rval);
	return 0;
}
