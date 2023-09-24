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
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	sort(all(b));
	vector<ll> sumb(m+1);
	rep(i, m) sumb[i+1] = sumb[i] + b[i];
	ll res = 0;
	rep(i, n) {
		int id = lower_bound(all(b), p-a[i]) - b.begin();
		res += id * (ll)a[i] + sumb[id] + p * (ll)(m-id);
	}
	cout << res << endl;
	return 0;
}
