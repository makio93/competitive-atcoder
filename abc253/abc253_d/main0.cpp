// 本番AC

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
	int n, a, b;
	cin >> n >> a >> b;
	ll res = (ll)n * (n+1) / 2;
	res -= (ll)(n/a) * (n/a+1) / 2 * a;
	res -= (ll)(n/b) * (n/b+1) / 2 * b;
	ll lval = lcm((ll)a, (ll)b);
	res += (n/lval) * (n/lval+1) / 2 * lval;
	cout << res << endl;
	return 0;
}
