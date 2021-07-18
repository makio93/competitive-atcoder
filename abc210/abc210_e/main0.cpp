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

// 本番AC

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), c(m);
	rep(i, m) cin >> a[i] >> c[i];
	map<int, int> pcnt;
	rep(i, m) {
		int pi = gcd(n, a[i]);
		if (pcnt.find(pi) == pcnt.end()) pcnt[pi] = c[i];
		else pcnt[pi] = min(pcnt[pi], c[i]);
	}
	vector<pair<int, int>> cal;
	for (auto p : pcnt) cal.emplace_back(p.second, p.first);
	sort(all(cal));
	auto itr = cal.begin();
	int gval = itr->second;
	ll res = (ll)(itr->first) * (n - gval);
	itr = next(itr);
	while (itr!=cal.end() && gval!=1) {
		int pgval = gval;
		gval = gcd(gval, itr->second);
		if (gval < pgval) res += (ll)(itr->first) * (pgval - gval);
		itr = next(itr);
	}
	if (gval != 1) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
