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
	int n, sx, sy, tx, ty;
	cin >> n >> sx >> sy >> tx >> ty;
	vector<int> x(n), y(n), r(n);
	rep(i, n) cin >> x[i] >> y[i] >> r[i];
	int sid = -1, tid = -1;
	rep(i, n) if ((ll)abs(sx-x[i])*abs(sx-x[i])+(ll)abs(sy-y[i])*abs(sy-y[i]) == (ll)r[i]*r[i]) {
		sid = i;
		break;
	}
	rep(i, n) if ((ll)abs(tx-x[i])*abs(tx-x[i])+(ll)abs(ty-y[i])*abs(ty-y[i]) == (ll)r[i]*r[i]) {
		tid = i;
		break;
	}
	dsu ds(n);
	rep(i, n) rep3(j, i+1, n) {
		ll d = (ll)abs(x[i]-x[j]) * abs(x[i]-x[j]) + (ll)abs(y[i]-y[j]) * abs(y[i]-y[j]);
		if (d<=(ll)(r[i]+r[j])*(r[i]+r[j]) && d>=(ll)(r[i]-r[j])*(r[i]-r[j])) ds.merge(i, j);
	}
	if (ds.same(sid, tid)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
