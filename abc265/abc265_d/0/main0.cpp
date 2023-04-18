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
	int n;
	ll p, q, r;
	cin >> n >> p >> q >> r;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> asum(n+1);
	rep(i, n) asum[i+1] += asum[i] + a[i];
	vector<bool> yids(n+1), zids(n+1);
	bool ok = false;
	rep3(i, 1, n+1) {
		int id = lower_bound(all(asum), asum[i]-p) - asum.begin();
		if (id<=n && asum[id]==asum[i]-p) yids[i] = true;
	}
	rep3(i, 1, n+1) {
		int id = lower_bound(all(asum), asum[i]-q) - asum.begin();
		if (id<=n && yids[id] && asum[id]==asum[i]-q) zids[i] = true;
	}
	rep3(i, 1, n+1) {
		int id = lower_bound(all(asum), asum[i]-r) - asum.begin();
		if (id<=n && zids[id] && asum[id]==asum[i]-r) {
			ok = true;
			break;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
