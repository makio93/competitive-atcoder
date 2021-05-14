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

// 解法を一部だけ見て実装、引き算式の分母を払って整数にしてみる、AC

int main() {
	int k;
	ll n, m;
	cin >> k >> n >> m;
	vector<ll> a(k);
	rep(i, k) cin >> a[i];
	vector<ll> b(k);
	ll bsum = 0;
	rep(i, k) {
		b[i] = (a[i] * m + 0.5) / n;
		bsum += b[i];
	}
	if (bsum > m) {
		priority_queue<pair<pair<ll, ll>, int>> que;
		rep(i, k) que.emplace(pair<ll,ll>(-llabs((ll)(b[i]-1)*n-(ll)a[i]*m),(ll)b[i]*n-(ll)a[i]*m), i);
		for (ll i=bsum; i>m; --i) {
			auto p = que.top(); que.pop();
			while (b[p.second] <= 0) {
				p = que.top(); que.pop();
			}
			b[p.second]--;
			que.emplace(pair<ll,ll>(-llabs((ll)(b[p.second]-1)*n-(ll)a[p.second]*m),(ll)b[p.second]*n-(ll)a[p.second]*m), p.second);
		}
	}
	else if (bsum < m) {
		priority_queue<pair<pair<ll, ll>, int>, vector<pair<pair<ll, ll>, int>>, greater<pair<pair<ll, ll>, int>>> que;
		rep(i, k) que.emplace(pair<ll,ll>(llabs((ll)(b[i]+1)*n-(ll)a[i]*m),(ll)b[i]*n-(ll)a[i]*m), i);
		for (ll i=bsum; i<m; ++i) {
			auto p = que.top(); que.pop();
			b[p.second]++;
			que.emplace(pair<ll,ll>(llabs((ll)(b[p.second]+1)*n-(ll)a[p.second]*m),(ll)b[p.second]*n-(ll)a[p.second]*m), p.second);
		}
	}
	rep(i, k) printf("%lld%c", b[i], (i<k-1?' ':'\n'));
	return 0;
}
