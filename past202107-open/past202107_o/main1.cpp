// 解説AC

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

const ll LINF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> a(n+1), b(n+1);
	rep3(i, 1, n+1) cin >> a[i] >> b[i];
	vector<ll> s(n+1);
	rep(i, n) s[i+1] = s[i] + a[i+1];
	vector<int> ids;
	ids.push_back(0);
	rep3(i, 1, n+1) if (b[i] > b[ids.back()]) ids.push_back(i);
	ids.push_back(n);
	int m = ids.size();
	multiset<pair<ll, ll>> st1;
	multiset<ll> st2;
	st1.emplace(s[ids[1]], 0);
	st2.insert(0);
	bool ok = true;
	ll rcost = -1;
	rep3(i, 1, m-1) {
		while (!st1.empty() && st1.begin()->first < b[ids[i]]) {
			st2.erase(st2.find(st1.begin()->second));
			st1.erase(st1.begin());
		}
		if (st1.empty()) {
			ok = false;
			break;
		}
		ll ncost = *st2.begin() + b[ids[i]];
		st1.emplace(s[ids[i+1]]-ncost, ncost);
		st2.insert(ncost);
		if (i == m-2) rcost = ncost;
	}
	if (!ok) cout << -1 << endl;
	else {
		cout << (s[n]-rcost) << endl;
	}
	return 0;
}
