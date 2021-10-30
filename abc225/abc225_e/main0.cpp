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
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<long double> s(n), f(n);
	rep(i, n) {
		s[i] = atan2((long double)(y[i]-1), (long double)(x[i])), f[i] = atan2((long double)(y[i]), (long double)(x[i]-1));
	}
	vector<pair<long double, long double>> fs(n);
	rep(i, n) fs[i] = { f[i], s[i] };
	sort(all(fs));
	int res = 0, pid = 0;
	while (pid < n) {
		++res;
		long double fi = fs[pid].first;
		++pid;
		while (pid<n && fs[pid].second<fi) ++pid;
	}
	cout << res << endl;
	return 0;
}
