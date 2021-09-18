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

// 本番WA

const vector<int> dx = { -1, 1, 0, 0 }, dy = { 0, 0, -1, 1 };
const string tar = "LRUD";

int main() {
	string s;
	ll k;
	cin >> s >> k;
	int n = s.length();
	ll c0 = 1, c1 = 0, cn = 0;
	set<pair<ll, ll>> visited;
	visited.emplace(0, 0);
	ll x = 0, y = 0;
	for (char ci : s) rep(i, 4) if (ci == tar[i]) {
		x += dx[i]; y += dy[i];
		if (visited.find({x, y}) == visited.end()) {
			++c1;
			visited.emplace(x, y);
		}
	}
	for (char ci : s) rep(i, 4) if (ci == tar[i]) {
		x += dx[i]; y += dy[i];
		if (visited.find({x, y}) == visited.end()) {
			++cn;
			visited.emplace(x, y);
		}
	}
	ll res = c0 + c1;
	if (k > 1LL) res += cn * (k - 1);
	cout << res << endl;
	return 0;
}
