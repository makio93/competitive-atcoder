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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	unordered_set<ll> ast;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int kcnt = 0;
	ll res = 0;
	rep(i, n) pq.push(a[i]);
	while (kcnt<k && !pq.empty()) {
		auto val = pq.top(); pq.pop();
		if (ast.find(val) != ast.end()) continue;
		ast.insert(val);
		++kcnt;
		if (kcnt == k) {
			res = val;
			break;
		}
		rep(i, n) pq.push(val+a[i]);
	}
	cout << res << endl;
	return 0;
}
