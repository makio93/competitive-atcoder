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

// 本番終了後,自力AC

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	set<ll> aval, bval;
	aval.insert(a[0]);
	bval.insert(b[0]);
	rep3(i, 1, n) {
		set<ll> aval2, bval2;
		for (ll val : aval) {
			aval2.insert(gcd(val, a[i]));
			aval2.insert(gcd(val, b[i]));
		}
		for (ll val : bval) {
			bval2.insert(gcd(val, a[i]));
			bval2.insert(gcd(val, b[i]));
		}
		swap(aval, aval2);
		swap(bval, bval2);
	}
	ll res = 0;
	for (ll val1 : aval) for (ll val2 : bval) res = max(res, lcm(val1, val2));
	cout << res << endl;
	return 0;
}
