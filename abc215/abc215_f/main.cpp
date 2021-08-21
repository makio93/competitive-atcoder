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

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<pair<int, int>> xy(n), yx(n);
	rep(i, n) xy[i] = { x[i], y[i] };
	rep(i, n) yx[i] = { y[i], x[i] };
	sort(all(xy));
	sort(all(yx));
	int mval = 0;
	for (int i=0; i<n-1-i; ++i) {
		mval = max(mval, min(abs(xy[i].first-xy[n-1-i].first), abs(xy[i].second-xy[n-1-i].second)));
		mval = max(mval, min(abs(yx[i].first-yx[n-1-i].first), abs(yx[i].second-yx[n-1-i].second)));
	}
	cout << mval << endl;
	return 0;
}
