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

// 自力AC

ll gcd(ll a, ll b) { return ((a < b) ? gcd(b, a) : (b == 0LL) ? a : gcd(b, a-b)); }

ll cross_product(pair<int, int> a, pair<int, int> b) {
	return (ll)a.first * b.second - (ll)a.second * b.first;
}

pair<int, int> sub_vector(pair<int, int> a, pair<int, int> b) {
	return { b.first - a.first, b.second - a.second };
}

ll lower_area(pair<int, int> a, pair<int, int> b) {
	auto s = sub_vector(a, b);
	if (s.second == 0) return 0LL;
	else {
		int c = abs(s.first), r = abs(s.second), g = gcd(c, r);
		return (ll)(c + 1) * (r + 1) / 2 - (g + 1) / 2 - max(0, s.second);
	}
}

ll upper_area(pair<int, int> a, pair<int, int> b) {
	auto s = sub_vector(a, b);
	if (s.second == 0) return llabs((ll)(s.first));
	else {
		int c = abs(s.first), r = abs(s.second), g = gcd(c, r);
		ll low = (ll)(c + 1) * (r + 1) / 2 - (g + 1) / 2;
		return (ll)(c + 1) * (r + 1) - low - (max(0, s.second) + 1);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	map<int, set<int>> xy;
	rep(i, n) xy[x[i]].insert(y[i]);
	map<int, int> lxy, hxy;
	for (auto p : xy) lxy[p.first] = (*p.second.begin());
	for (auto p : xy) hxy[p.first] = (*p.second.rbegin());
	vector<pair<int, int>> lver, hver;
	for (auto v : lxy) {
		while ((int)(lver.size()) >= 2) {
			int vlen = lver.size();
			auto dv1 = sub_vector(lver[vlen-2], lver[vlen-1]), dv2 = sub_vector(lver[vlen-2], v);
			ll cprod = cross_product(dv1, dv2);
			if (cprod > 0LL) break;
			lver.pop_back();
		}
		lver.push_back(v);
	}
	for (auto v : hxy) {
		while ((int)(hver.size()) >= 2) {
			int vlen = hver.size();
			auto dv1 = sub_vector(hver[vlen-2], hver[vlen-1]), dv2 = sub_vector(hver[vlen-2], v);
			ll cprod = cross_product(dv1, dv2);
			if (cprod < 0LL) break;
			hver.pop_back();
		}
		hver.push_back(v);
	}
	ll lcnt = 0, hcnt = 0;
	for (int i=0; i<(int)(lver.size()); ++i) {
		if (i == (int)(lver.size())-1) lcnt += lver[i].second;
		else {
			lcnt += lower_area(lver[i], lver[i+1]);
			lcnt += (ll)min(lver[i].second, lver[i+1].second) * abs(sub_vector(lver[i], lver[i+1]).first);
		}
	}
	for (int i=0; i<(int)(hver.size()); ++i) {
		if (i == (int)(hver.size())-1) hcnt += hver[i].second + 1;
		else {
			hcnt += upper_area(hver[i], hver[i+1]);
			hcnt += (ll)min(hver[i].second, hver[i+1].second) * abs(sub_vector(hver[i], hver[i+1]).first);
		}
	}
	ll res = hcnt - lcnt - n;
	cout << res << endl;
	return 0;
}
