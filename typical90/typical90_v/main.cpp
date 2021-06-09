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

ll gcd(ll a, ll b) { return ((a < b) ? gcd(b, a) : (!b ? a : gcd(b, a%b))); }

int main() {
	vector<ll> abc(3);
	rep(i, 3) cin >> abc[i];
	ll gval = abc[0];
	rep3(i, 1, 3) gval = gcd(gval, abc[i]);
	rep(i, 3) abc[i] /= gval;
	ll res = 0;
	rep(i, 3) res += abc[i] - 1;
	cout << res << endl;
	return 0;
}
