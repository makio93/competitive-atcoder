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

// 本番WA1

int main() {
	ll n;
	cin >> n;
	vector<ll> divs;
	for (ll i=1; i*i<=n; ++i) if (n%i == 0) {
		divs.push_back(i);
		divs.push_back(n/i);
	}
	sort(all(divs));
	ll res = 0;
	int m = divs.size();
	rep3(i, 0, m) res += (n / (ll)(divs[i])) * divs[i];
	cout << res << endl;
	return 0;
}
