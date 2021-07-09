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

const ll INF = (ll)(1e15);

int acnt(vector<vector<ll>>& a, ll c, ll p) {
	int n = a.size();
	vector<vector<ll>> dist(n, vector<ll>(n, INF));
	rep(i, n) rep(j, n) {
		if (a[i][j] == -1) dist[i][j] = c;
		else dist[i][j] = a[i][j];
	}
	rep(i2, n) rep(i, n) rep3(j, i+1, n) {
		ll di = min({dist[i][j], dist[j][i], dist[i][i2]+dist[i2][j], dist[j][i2]+dist[i2][i]});
		dist[i][j] = dist[j][i] = di;
	}
	ll res = 0;
	rep(i, n) rep3(j, i+1, n) if (dist[i][j] <= p) ++res;
	return res;
}

int main() {
	int n, k;
	ll p;
	cin >> n >> p >> k;
	vector<vector<ll>> a(n, vector<ll>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	vector<ll> res(2);
	ll l = 0, r = p + 5;
	if (acnt(a, r, p) == k) {
		cout << "Infinity" << endl;
		return 0;
	}
	while (r-l > 1LL) {
		ll c = (l+r) / 2;
		if (acnt(a, c, p) >= k) l = c;
		else r = c;
	}
	res[0] = l;
	l = 0; r = p + 5;
	while (r-l > 1LL) {
		ll c = (l+r) / 2;
		if (acnt(a, c, p) <= k) r = c;
		else l = c;
	}
	res[1] = r;
	cout << max(0LL, res[0]-res[1]+1) << endl;
	return 0;
}
