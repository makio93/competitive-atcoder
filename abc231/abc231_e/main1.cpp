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

// 解説AC

unordered_map<ll, ll> memo;
ll calc(vector<ll>& a, ll x, int id=0) {
	if (memo.find(x) != memo.end()) return memo[x];
	if (id == (int)(a.size())-1) return memo[x] = x/a[id];
	else {
		ll aval0 = x / a[id+1] * a[id+1], aval1 = aval0 + a[id+1], res = calc(a, aval0, id+1) + (x-aval0)/a[id];
		if (x-aval0 != 0) res = min(res, calc(a, aval1, id+1)+(aval1-x)/a[id]);
		return memo[x] = res;
	}
}

int main() {
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	cout << calc(a, x) << endl;
	return 0;
}
