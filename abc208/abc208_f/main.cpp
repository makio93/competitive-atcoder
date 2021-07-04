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

using mint = modint1000000007;
int k;

map<pair<ll, int>, mint> memo;

mint f(ll n, int m) {
	if (memo.find({n, m}) != memo.end()) return (memo[{n,m}]);
	if (n == 0) return (memo[{n,m}] = 0);
	if (m == 0) return (memo[{n,m}] = mint(n).pow(k));
	if (n==1 || m==1) 
	return (memo[{n,m}] = (f(n-2,m)+2*f(n-1,m-1)+f(n,m-2)));
}

int main() {
	ll n; int m;
	cin >> n >> m >> k;
	mint res = f(n, m);
	cout << res.val() << endl;
	return 0;
}
