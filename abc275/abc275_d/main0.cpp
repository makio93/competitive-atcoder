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

const int INF = (int)(1e9);

int main() {
	ll n;
	cin >> n;
	map<ll, ll> memo;
	auto calc = [&](auto calc, ll val) -> ll {
		if (memo.find(val) != memo.end()) return memo[val];
		if (val == 0) return memo[val] = 1;
		else return memo[val] = calc(calc, val/3) + calc(calc, val/2);
	};
	cout << calc(calc, n) << endl;
	return 0;
}
