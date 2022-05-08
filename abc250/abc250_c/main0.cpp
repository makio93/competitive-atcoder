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
	int n, q;
	cin >> n >> q;
	vector<int> a(n), r(n);
	iota(all(a), 0);
	rep(i, n) r[a[i]] = i;
	rep(i, q) {
		int xi;
		cin >> xi;
		--xi;
		if (r[xi] != n-1) {
			int li = r[xi], ri = li + 1;
			swap(r[xi], r[a[ri]]);
			swap(a[li], a[ri]);
		}
		else {
			int ri = r[xi], li = ri - 1;
			swap(r[a[li]], r[xi]);
			swap(a[li], a[ri]);
		}
	}
	rep(i, n) printf("%d%c", a[i]+1, (i<n-1?' ':'\n'));
	return 0;
}
