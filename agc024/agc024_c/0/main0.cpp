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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll res = 0;
	int val = 0;
	bool ok = true;
	repr(i, n) {
		if (a[i]<val || a[i]>i) {
			ok = false;
			break;
		}
		if (a[i] > val) {
			res += a[i];
			val = a[i];
		}
		val = max(0, val-1);
	}
	if (ok) cout << res << endl;
	else cout << -1 << endl;
	return 0;
}
