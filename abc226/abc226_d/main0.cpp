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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

int main() {
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<pair<ll, ll>> xy(n);
	rep(i, n) xy[i] = { x[i], y[i] };
	sort(all(xy));
	set<pair<ll, ll>> rcnt;
	rep(i, n) rep3(j, i+1, n) {
		ll dx = xy[j].first - xy[i].first, dy = xy[j].second - xy[i].second;
		if (dy == 0) dx = 1;
		else if (dx == 0) dy = 1;
		else {
			ll gval = gcd(dy, dx);
			dy /= gval; dx /= gval;
		}
		rcnt.emplace(dy, dx);
	}
	cout << ((int)(rcnt.size())*2) << endl;
	return 0;
}
