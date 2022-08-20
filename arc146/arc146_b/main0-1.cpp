// 本番WA

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
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll res = 0;
	repr(i, 30) {
		ll bt = res | (1LL<<i);
		vector<pair<ll, int>> tvals(n);
		rep(j, n) tvals[j] = { max(0LL, bt-a[j]), j };
		sort(all(tvals));
		ll sum = 0;
		rep(j, k) sum += tvals[j].first;
		if (sum > (ll)m) continue;
		m -= sum;
		rep(j, k) a[tvals[j].second] += tvals[j].first;
		res = bt;
	}
	cout << res << endl;
	return 0;
}
