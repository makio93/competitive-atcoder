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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	rep(i, n) cin >> l[i] >> r[i];
	int rmin = (int)(1.1e9), lmax = 0;
	// vector<int> res(n);
	rep(i, n) {
		rmin = min(rmin, r[i]);
		lmax = max(lmax, l[i]);
		cout << max(0, (lmax-rmin+1)/2) << endl;
	}
	return 0;
}
