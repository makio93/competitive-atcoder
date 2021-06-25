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

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b;
	rep(i, n) cin >> a[i];
	ll sum = 0;
	rep(i, n) sum += a[i];
	if (sum % 10 != 0) {
		cout << "No" << endl;
		return 0;
	}
	sum /= 10;
	rep(i2, 2) rep(i, n) b.push_back(a[i]);
	ll val = 0;
	int r = 0;
	bool ok = false;
	rep(l, n) {
		while (val < sum) {
			val += b[r];
			++r;
			if (r >= 2*n) break;
		}
		if (val == sum) {
			ok = true;
			break;
		}
		if (r >= 2*n) break;
		val -= b[l];
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
