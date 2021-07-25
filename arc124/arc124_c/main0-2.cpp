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

// 本番WA,2

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

map<ll, int> pcnt(ll aval) {
	map<ll, int> res;
	ll nval = aval;
	for (ll i=2; i*i<=nval; ++i) {
		while (nval%i == 0) {
			nval /= i;
			res[i]++;
		}
	}
	if (nval > 1) res[nval]++;
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<pair<vector<map<ll, int>>, int>> pab(n);
	rep(i, n) {
		pab[i] = { { pcnt(a[i]), pcnt(b[i]) }, i };
		if (pab[i].first[0] > pab[i].first[1]) {
			swap(pab[i].first[0], pab[i].first[1]);
			swap(a[i], b[i]);
		}
	}
	sort(all(pab));
	vector<ll> a2 = a, b2 = b;
	rep(i, n) {
		a[i] = a2[pab[i].second];
		b[i] = b2[pab[i].second];
	}
	ll aval = a[0], bval = b[0];
	rep3(i, 1, n) {
		ll aval1 = gcd(aval, a[i]), bval1 = gcd(bval, b[i]);
		ll aval2 = gcd(aval, b[i]), bval2 = gcd(bval, a[i]);
		ll lval1 = lcm(aval1, bval1), lval2 = lcm(aval2, bval2);
		if (a[i] == b[i]) { aval = aval1; bval = bval1; }
		else if (lval1 > lval2) { aval = aval1; bval = bval1; }
		else if (lval1 < lval2) { aval = aval2; bval = bval2; }
		else if (abs(aval1-a[i])+abs(bval1-b[i]) >= abs(aval2-a[i])+abs(bval2-b[i])) { aval = aval1; bval = bval1; }
		else { aval = aval2; bval = bval2; }
	}
	cout << lcm(aval, bval) << endl;
	return 0;
}
