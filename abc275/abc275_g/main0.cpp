// 自力WA

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
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	vector<int> ids1(n), ids2(n);
	iota(all(ids1), 0);
	iota(all(ids2), 0);
	sort(all(ids1), [&](int li, int ri) -> bool {
		return make_pair(c[li]/a[li], c[li]/b[li]) > make_pair(c[ri]/a[ri], c[ri]/b[ri]);
	});
	sort(all(ids2), [&](int li, int ri) -> bool {
		return make_pair(c[li]/b[li], c[li]/a[li]) > make_pair(c[ri]/b[ri], c[ri]/a[ri]);
	});
	double mval = 0.0, rval = 0;
	ll vsum = 0, csum1 = 0, csum2 = 0;
	rep(i, n) {
		vsum += c[ids1[i]];
		csum1 += a[ids1[i]];
		csum2 += b[ids1[i]];
		mval = max(mval, vsum/(double)max(csum1,csum2));
	}
	rval += mval;
	mval = 0.0;
	vsum = 0, csum1 = 0, csum2 = 0;
	rep(i, n) {
		vsum += c[ids2[i]];
		csum1 += a[ids2[i]];
		csum2 += b[ids2[i]];
		mval = max(mval, vsum/(double)max(csum1,csum2));
	}
	rval += mval;
	rval /= 2.0;
	printf("%.15f\n", rval);
	return 0;
}
