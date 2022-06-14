// 解法のみ見て，自力で実装,AC

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

int n;
map<pair<ll, int>, ll> memo;
ll calc(vector<ll>& a, ll x, int id) {
	if (memo.find({x, id}) != memo.end()) return memo[{x, id}];
	if (id >= n) return (memo[{x, id}] = 0);
	else if (id == n-1) return (memo[{x, id}] = x/a[id]);
	else {
		ll aval1 = x / a[id+1] * a[id+1];
		return (memo[{x, id}] = min(calc(a,aval1,id+1)+(x-aval1)/a[id], calc(a,aval1+a[id+1],id+1)+(aval1+a[id+1]-x)/a[id]));
	}
}

int main() {
	ll x;
	cin >> n >> x;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	if (n == 1) cout << (x/a[0]) << endl;
	else {
		ll aval0 = x / a[1] * a[1], res = min(calc(a,aval0,1)+(x-aval0), calc(a,aval0+a[1],1)+(aval0+a[1]-x));
		cout << res << endl;
	}
	return 0;
}
