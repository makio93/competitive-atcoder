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
	int n, m, t;
	cin >> n >> m >> t;
	vector<int> a(n), b(n);
	rep3(i, 1, n) cin >> a[i];
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		--xi;
		b[xi] = yi;
	}
	ll nval = t;
	bool ok = true;
	rep(i, n-1) {
		if (a[i+1] >= nval) {
			ok = false;
			break;
		}
		nval -= a[i+1];
		nval += b[i+1];
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
