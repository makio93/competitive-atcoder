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

const int INF = (int)(1.1e9);

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> ai(n);
	rep(i, n) cin >> ai[i];
	sort(all(ai));
	ll lval = 0, rval = INF;
	while (rval-lval > 1) {
		ll cval = lval + (rval-lval) / 2;
		auto bi = ai;
		bool ok = true;
		int rid = n - 1;
		rep(i, n) {
			if (bi[i] >= cval) break;
			while (bi[i]<cval && rid>i && bi[rid]>=cval) {
				int tcnt = (cval-bi[i]+a-1) / a, scnt = (bi[rid]-cval) / b;
				int mcnt = min(tcnt, scnt);
				bi[i] += mcnt * a;
				bi[rid] -= mcnt * b;
				while (bi[i]<cval && bi[rid]-b<cval && rid>i) --rid;
			}
			if (bi[i] < cval) {
				ok = false;
				break;
			}
		}
		if (ok) lval = cval;
		else rval = cval;
	}
	cout << lval << endl;
	return 0;
}
