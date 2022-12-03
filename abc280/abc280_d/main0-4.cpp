// 自力WA

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
	vector<pair<ll, int>> plst;
	for (ll i=2; i*i<=k; ++i) if (k%i == 0) {
		plst.emplace_back(i, 0);
		while (k%i == 0) {
			k /= i;
			plst.back().second++;
		}
	}
	if (k > 1) plst.emplace_back(k, 1);
	ll res = 1;
	for (const auto& pi : plst) res = max(res, pi.first*pi.second);
	cout << res << endl;
	return 0;
}
