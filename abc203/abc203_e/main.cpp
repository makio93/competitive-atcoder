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

int main() {
	int n, m;
	cin >> n >> m;
	map<ll, set<ll>> xy;
	rep(i, m) {
		ll xi, yi;
		cin >> xi >> yi;
		xy[xi].insert(yi);
	}
	set<ll> wi;
	wi.insert(n);
	for (auto itr=xy.begin(); itr!=xy.end(); ++itr) {
		if (itr->first == 0LL) continue;
		auto to = itr->second;
		for (ll p : to) {
			if (wi.find(p-1) != wi.end()) wi.insert(p);
			if (wi.find(p+1) != wi.end()) wi.insert(p);
		}
		for (ll p : to) {
			if (wi.find(p) != wi.end()) wi.erase(p);
		}
	}
	cout << (int)(wi.size()) << endl;
	return 0;
}
