// 

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
	ll asum = 0;
	rep(i, n) asum += a[i];
	ll asub = l - asum;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	rep(i, n) pq.push(a[i]);
	if (asub > 0) pq.push(asub);
	ll res = 0;
	while ((int)(pq.size()) > 1) {
		ll val1 = pq.top(); pq.pop();
		ll val2 = pq.top(); pq.pop();
		res += val1 + val2;
		pq.push(val1+val2);
	}
	cout << res << endl;
	return 0;
}
