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

int main() {
	int k;
	ll n, m;
	cin >> k >> n >> m;
	vector<ll> a(k);
	rep(i, k) cin >> a[i];
	vector<ll> b(k);
	ll bsum = 0;
	rep(i, k) {
		b[i] = (a[i] * m + 0.5+(1e-7)) / n;
		bsum += b[i];
	}
	if (bsum > m) {
		priority_queue<pair<pair<double, double>, int>> que;
		rep(i, k) que.emplace(pair<double,double>(-fabs((double)(b[i]-1)/m-(double)a[i]/n),(double)b[i]/m-(double)a[i]/n), i);
		for (ll i=bsum; i>m; --i) {
			auto p = que.top(); que.pop();
			while (b[p.second] <= 0) {
				p = que.top(); que.pop();
			}
			b[p.second]--;
			que.emplace(pair<double,double>(-fabs((double)(b[p.second]-1)/m-(double)a[p.second]/n),(double)b[p.second]/m-(double)a[p.second]/n), p.second);
		}
	}
	else if (bsum < m) {
		priority_queue<pair<pair<double,double>, int>, vector<pair<pair<double,double>, int>>, greater<pair<pair<double,double>, int>>> que;
		rep(i, k) que.emplace(pair<double,double>(fabs((double)(b[i]+1)/m-(double)a[i]/n),(double)b[i]/m-(double)a[i]/n), i);
		for (ll i=bsum; i<m; ++i) {
			auto p = que.top(); que.pop();
			b[p.second]++;
			que.emplace(pair<double,double>(fabs((double)(b[p.second]+1)/m-(double)a[p.second]/n),(double)b[p.second]/m-(double)a[p.second]/n), p.second);
		}
	}
	rep(i, k) printf("%lld%c", b[i], (i<k-1?' ':'\n'));
	return 0;
}
