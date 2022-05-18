// 解説AC

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

const ll LINF = (ll)(1e18);

int main() {
    int n, m, k, l;
	cin >> n >> m >> k >> l;
	vector<int> a(n), b(l);
    rep(i, n) { cin >> a[i]; a[i]--; }
    rep(i, l) { cin >> b[i]; b[i]--; }
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		int ui, vi, ci;
		cin >> ui >> vi >> ci;
		--ui; --vi;
		g[ui].emplace_back(vi, ci);
		g[vi].emplace_back(ui, ci);
	}
    vector<unordered_map<int, ll>> dist(n);
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    rep(i, l) pq.emplace(0, b[i], a[b[i]]);
    while (!pq.empty()) {
        auto pi = pq.top(); pq.pop();
        ll di = get<0>(pi); int vi = get<1>(pi), ai = get<2>(pi);
        if ((int)(dist[vi].size())>=2 || dist[vi].find(ai)!=dist[vi].end()) continue;
        dist[vi][ai] = di;
        for (auto tpi : g[vi]) {
            ll ndi = di + tpi.second; int ti = tpi.first;
            pq.emplace(ndi, ti, ai);
        }
    }
    rep(i, n) {
        ll res = LINF;
        if (!dist[i].empty()) {
            for (auto pi : dist[i]) if (pi.first != a[i]) res = min(res, pi.second);
        }
        if (res == LINF) res = -1;
        cout << res;
        if (i < n-1) cout << ' ';
        else cout << endl;
    }
    return 0;
}
