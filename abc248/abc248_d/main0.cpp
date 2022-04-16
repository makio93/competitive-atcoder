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
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int>> vlst(n);
	rep(i, n) vlst[a[i]].push_back(i);
	cin >> q;
	rep(i, q) {
		int l, r, x;
		cin >> l >> r >> x;
		--l; --r; --x;
		int res = 0;
		if (!vlst[x].empty()) {
			res = upper_bound(all(vlst[x]), r) - lower_bound(all(vlst[x]), l);
		}
		cout << res << endl;
	}
	return 0;
}
