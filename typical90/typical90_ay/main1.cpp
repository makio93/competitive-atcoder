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

// 解説AC

int main() {
	int n, k; ll p;
	cin >> n >> k >> p;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	int mid = n / 2;
	vector<vector<ll>> v1(n+1), v2(n+1);
	rep(i, (1<<mid)) {
		ll sum = 0; int cnt = 0;
		rep(j, mid) if ((i>>j) & 1) { sum += a[j]; ++cnt; }
		v1[cnt].push_back(sum);
	}
	rep(i, (1<<(n-mid))) {
		ll sum = 0; int cnt = 0;
		rep(j, (n-mid)) if ((i>>j) & 1) { sum += a[mid+j]; ++cnt; }
		v2[cnt].push_back(sum);
	}
	rep(i, n+1) { sort(all(v1[i])); sort(all(v2[i])); }
	ll res = 0;
	rep(i, k+1) rep(j, (int)(v1[i].size())) {
		int k2 = k - i; ll p2 = p - v1[i][j];
		res += upper_bound(all(v2[k2]), p2) - v2[k2].begin();
	}
	cout << res << endl;
	return 0;
}
