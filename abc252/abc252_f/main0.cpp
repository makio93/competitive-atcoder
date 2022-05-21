// 本番WA

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
	int n;
	ll l;
	cin >> n >> l;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	vector<ll> asum(n+1);
	rep(i, n) asum[i+1] = asum[i] + a[i];
	if (asum[n] < l) asum.push_back(l);
	auto dfs = [&](auto dfs, int li, int ri) -> ll {
		if (ri-li <= 1) return 0;
		ll lval = asum[li], rval = asum[ri];
		ll ctar = lval + (rval-lval) / 2;
		int cid = upper_bound(all(asum), ctar) - asum.begin();
		if (asum[cid]-ctar > ctar-asum[cid-1]) --cid;
		return dfs(dfs, li, cid) + dfs(dfs, cid, ri) + (rval-lval);
	};
	ll res = dfs(dfs, 0, (int)(asum.size())-1);
	cout << res << endl;
	return 0;
}
