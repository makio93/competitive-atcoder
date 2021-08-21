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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
//ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	set<int> primes;
	rep(i, n) {
		int ai = a[i];
		for (ll i2=2; i2*i2<=(ll)ai; ++i2) {
			while ((ll)ai%i2 == 0LL) {
				ai /= i2;
				primes.insert((int)i2);
			}
		}
		if (ai > 1) primes.insert(ai);
	}
	vector<bool> check(m+1);
	for (int pi : primes) {
		int j = pi;
		if (j > m) continue;
		if (check[j]) continue;
		while (j <= m) {
			check[j] = true;
			j += pi;
		}
	}
	vector<int> res;
	res.push_back(1);
	rep3(i, 2, m+1) if (!check[i]) res.push_back(i);
	sort(all(res));
	int x = res.size();
	cout << x << endl;
	rep(i, x) cout << res[i] << endl;
	return 0;
}
