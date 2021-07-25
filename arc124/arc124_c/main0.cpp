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

// 本番WA,1

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

ll pcnt(ll aval) {
	vector<pair<ll, int>> res;
	ll nval = aval;
	for (ll i=2; i*i<=nval; ++i) {
		if (nval%i == 0) res.emplace_back(i, 0);
		while (nval%i == 0) {
			nval /= i;
			res.back().second++;
		}
	}
	if (nval > 1) res.emplace_back(nval, 1);
	return (ll)(res.size());
}

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	rep(i, n) if (a[i] > b[i]) swap(a[i], b[i]);
	vector<pair<ll, ll>> ab(n);
	rep(i, n) ab[i] = { a[i], b[i] };
	sort(ab.rbegin(), ab.rend());
	rep(i, n) a[i] = ab[i].first;
	rep(i, n) b[i] = ab[i].second;
	ll aval = a[0], bval = b[0];
	rep3(i, 1, n) {
		ll aval1 = gcd(aval, a[i]), bval1 = gcd(bval, b[i]);
		ll aval2 = gcd(aval, b[i]), bval2 = gcd(bval, a[i]);
		ll pcnt1 = pcnt(aval1)+pcnt(bval1), pcnt2 = pcnt(aval2)+pcnt(bval2);
		ll lval1 = lcm(aval1, bval1), lval2 = lcm(aval2, bval2);
		if (a[i] == b[i]) { aval = aval1; bval = bval1; }
		else if (lval1 > lval2) { aval = aval1; bval = bval1; }
		else if (lval1 < lval2) { aval = aval2; bval = bval2; }
		else if (pcnt1 < pcnt2) { aval = aval1; bval = bval1; }
		else if (pcnt1 > pcnt2) { aval = aval2; bval = bval2; }
		else { aval = aval1; bval = bval1; }
	}
	cout << lcm(aval, bval) << endl;
	return 0;
}
