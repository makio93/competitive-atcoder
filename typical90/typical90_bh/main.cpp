#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> llen(n), rlen(n), ldp(n+1, INF), rdp(n+1, INF);
	ldp[0] = 0;
	rep(i, n) {
		int d = lower_bound(all(ldp), a[i]) - ldp.begin();
		if (d < (int)(ldp.size())) ldp[d] = a[i];
		llen[i] = d;
	}
	rdp[0] = 0;
	repr(i, n) {
		int d = lower_bound(all(rdp), a[i]) - rdp.begin();
		if (d < (int)(rdp.size())) rdp[d] = a[i];
		rlen[i] = d;
	}
	int res = 0;
	rep(i, n) res = max(res, llen[i]+rlen[i]-1);
	cout << res << endl;
	return 0;
}
