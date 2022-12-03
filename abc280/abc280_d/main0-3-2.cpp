// 本番WA3-2

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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
	ll k;
	cin >> k;
	ll mval = (ll)(1e6);
	map<ll, int> klst;
	for (ll i=2; i*i<=k; ++i) {
		while (k%i == 0) {
			k /= i;
			klst[i]++;
		}
	}
	if (k > 1) klst[k]++;
	ll res = 1;
	auto ritr = klst.rbegin();
	while (ritr!=klst.rend() && ritr->first>=mval) {
		res = max(res, ritr->first*ritr->second);
		for (ll i1=2; i1<=ritr->second; ++i1) {
			ll rval = i1;
			for (ll i=2; i*i<=rval; ++i) {
				while (rval%i == 0) {
					if (klst.find(i)!=klst.end() && klst[i]>0) {
						klst[i]--;
						if (klst[i] == 0) klst.erase(i);
					}
					rval /= i;
				}
			}
			if (rval > 1) {
				if (klst.find(rval)!=klst.end() && klst[rval]>0) {
					klst[rval]--;
					if (klst[rval] == 0) klst.erase(rval);
				}
			}
		}
		ll tmp = ritr->first;
		++ritr;
		klst.erase(tmp);
	}
	ll tval = 1;
	while (!klst.empty()) {
		++tval;
		ll rval = tval;
		for (ll i=2; i*i<=rval; ++i) {
			while (rval%i == 0) {
				if (klst.find(i)!=klst.end() && klst[i]>0) {
					klst[i]--;
					if (klst[i] == 0) klst.erase(i);
				}
				rval /= i;
			}
		}
		if (rval > 1) {
			if (klst.find(rval)!=klst.end() && klst[rval]>0) {
				klst[rval]--;
				if (klst[rval] == 0) klst.erase(rval);
			}
		}
		res = max(res, tval);
	}
	cout << res << endl;
	return 0;
}
