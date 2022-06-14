// 本番実装,未完成,解けない

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

const ll INF = (ll)(1.5e18);
unordered_map<ll, ll> memo;
int n;
vector<ll> a;
ll dfs(ll x) {
	if (memo.find(x) != memo.end()) return memo[x];
	if (x == 0) return (memo[x] = 0);
	else if (x == 1) return (memo[x] = 1);
	else {
		ll res = INF;
		int d = lower_bound(all(a), x) - a.begin();
		if (d < n) {
			ll val = a[d];
			res = min(res, 1+dfs(a[d]-x));
		}
		else {
			ll dcnt = (x+a[n-1]-1) / a[n-1];
			res = min(res, dfs(dcnt*a[n-1])+dfs(dcnt*a[n-1]-x));
		}
		/* 実装途中
		repr(i, d) {
			if (x)
		}
		*/
	}
}

int main() {
	ll x;
	cin >> n >> x;
	a = vector<ll>(n);
	rep(i, n) cin >> a[i];
	cout << dfs(x) << endl;
	return 0;
}
