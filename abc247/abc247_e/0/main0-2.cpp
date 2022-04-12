// 終了後,自力AC

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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int xl = 0, xr = -1, nl = 0, nr = -1;
	ll res = 0;
	rep(i, n) {
		if (a[i] > x) xl = n;
		else if (a[i] == x) {
			xl = min(xl, i);
			xr = i;
		}
		else if (xl == n) xl = i;
		if (a[i] < y) nl = n;
		else if (a[i] == y) {
			nl = min(nl, i);
			nr = i;
		}
		else if (nl == n) nl = i;
		if (xl!=n && nl!=n) res += max(0, min(xr,nr)-max(xl,nl)+1);
	}
	cout << res << endl;
	return 0;
}
