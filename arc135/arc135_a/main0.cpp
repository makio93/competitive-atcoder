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

// 本番AC

using mint = modint998244353;

int main() {
	ll x;
	cin >> x;
	priority_queue<pair<ll, ll>> pq;
	pq.emplace(x, 1);
	while ((pq.top().first/2) > pq.top().first/((pq.top().first+1)/2)) {
		auto [nx, ncnt] = pq.top(); pq.pop();
		while (!pq.empty() && pq.top().first==nx) {
			ncnt += pq.top().second;
			pq.pop();
		}
		pq.emplace(nx/2, ncnt);
		pq.emplace((nx+1)/2, ncnt);
	}
	mint res = 1;
	while (!pq.empty()) {
		res *= mint(pq.top().first).pow(pq.top().second);
		pq.pop();
	}
	cout << res.val() << endl;
	return 0;
}
