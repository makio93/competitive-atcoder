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
	int n, m;
	cin >> n >> m;
	vector<int> p(n), l(m), d(m);
	rep(i, n) cin >> p[i];
	rep(i, m) cin >> l[i];
	rep(i, m) cin >> d[i];
	sort(all(p));
	vector<pair<int, int>> ld(m);
	rep(i, m) ld[i] = { l[i], d[i] };
	sort(all(ld));
	ll res = accumulate(all(p), 0LL);
	int id = 0;
	priority_queue<int> pq;
	rep(i, n) {
		while (id<m && ld[id].first<=p[i]) {
			pq.push(ld[id].second);
			++id;
		}
		if (pq.empty()) continue;
		res -= pq.top(); pq.pop();
	}
	cout << res << endl;
	return 0;
}
