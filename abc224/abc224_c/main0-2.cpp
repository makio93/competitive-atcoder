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

const ll ADD = (ll)(1e9);
const ll INF = (ll)(1e18);

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
	vector<map<pair<ll, ll>, int>> rcnt(n);
	int sub = 0;
	repr(i, n) rep3(j, i+1, n) {
		if (xy[i].first != xy[j].first) {
			ll dx = xy[j].first - xy[i].first, dy = xy[j].second - xy[i].second;
			if (dy == 0) dx /= abs(dx);
			else {
				ll gi = gcd(abs(dx), abs(dy));
				dx /= gi; dy /= gi;
			}
			if (rcnt[j].find({dx,dy}) != rcnt[j].end()) sub += rcnt[j][{dx,dy}];
			rcnt[i][{dx,dy}]++;
		}
		else {
			if (rcnt[j].find({0,INF}) != rcnt[j].end()) sub += rcnt[j][{0,INF}];
			rcnt[i][{0,INF}]++;
		}
	}
	int res = (ll)n * (n-1) * (n-2) / 6 - sub;
	cout << res << endl;
	return 0;
}
