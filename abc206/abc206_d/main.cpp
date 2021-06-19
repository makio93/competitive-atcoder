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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	dsu d((int)(2e5)+1);
	rep(i, n/2) {
		d.merge(a[i], a[n-1-i]);
	}
	ll res = 0;
	auto dl = d.groups();
	for (auto v : dl) if ((int)(v.size()) > 1) {
		res += (int)(v.size()) - 1;
	}
	cout << res << endl;
	return 0;
}
