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
	vector<int> t(m), w(m), s(m);
	rep(i, m) cin >> t[i] >> w[i] >> s[i];
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	rep(i, m) pq.emplace(t[i], 1, i);
	set<int> st;
	rep(i, n) st.insert(i);
	vector<ll> res(n);
	while (!pq.empty()) {
		auto [ti, bi, id] = pq.top(); pq.pop();
		if (bi == 0) st.insert(id);
		else {
			if (st.empty()) continue;
			int si = *st.begin();
			res[si] += w[id];
			st.erase(si);
			pq.emplace(ti+s[id], 0, si);
		}
	}
	rep(i, n) cout << res[i] << endl;
	return 0;
}
