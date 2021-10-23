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

// 本番TLE

const ll ADD = (ll)(1e9);

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
	int n;
	cin >> n;
	vector<pair<ll, ll>> xy(n);
	rep(i, n) cin >> xy[i].first >> xy[i].second;
	rep(i, n) {
		xy[i].first += ADD;
		xy[i].second += ADD;
	}
	sort(all(xy));
	int res = 0;
	rep(i, n) rep3(j, i+1, n) rep3(k, j+1, n) {
		if (xy[i].first!=xy[j].first && xy[j].first!=xy[k].first) {
			ll x1 = xy[j].first - xy[i].first, x2 = xy[k].first - xy[j].first;
			ll y1 = xy[j].second - xy[i].second, y2 = xy[k].second - xy[j].second;
			if (y1 == 0) x1 /= abs(x1);
			else {
				ll g1 = gcd(abs(x1), abs(y1));
				x1 /= g1; y1 /= g1;
			}
			if (y2 == 0) x2 /= abs(x2);
			else {
				ll g2 = gcd(abs(x2), abs(y2));
				x2 /= g2; y2 /= g2;
			}
			if (x1!=x2 || y1!=y2) ++res;
		}
		else if (xy[i].first!=xy[j].first || xy[j].first!=xy[k].first) ++res;
	}
	cout << res << endl;
	return 0;
}
