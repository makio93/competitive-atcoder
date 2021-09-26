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

// 本番,未完成

using mint = modint998244353;

int main() {
	ll n, d;
	cin >> n >> d;
	mint res = 0;
	map<pair<ll, ll>, mint> memo;
	for (ll i=n-1; i>=1; --i) {
		ll li = min(n, i+d) - i, ri = d - li;
		if (li+ri<d) continue;
		if (memo.find({li, ri}) != memo.end()) res += memo[{li, ri}];
		mint val = 0;
		for (ll j=li,j2=ri; j2<=li; --j,++j2) {
			if (j == 0) val += (mint(2).pow(j2)) * 2;
			else if (j2 != 0) val += (mint(2).pow(j)) * (mint(2).pow(j2-1));
		}
		res += val;
		memo[{li, ri}] = val;
	}
	cout << res.val() << endl;
	return 0;
}
