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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);
using S = pair<int, int>;
S op(S a, S b) { return min(a, b); }
S e() { return { INF, -1 }; }

int main() {
	int n, q;
	cin >> n;
	vector<vector<pair<int, int>>> g(n);
	vector<int> w(n-1);
	rep(i, n-1) {
		int ui, vi, wi;
		cin >> ui >> vi >> wi;
		--ui; --vi;
		g[ui].emplace_back(vi, i);
		g[vi].emplace_back(ui, i);
		w[i] = wi;
	}
	vector<int> vtoi(n, INF), wlst;
	vector<pair<int, int>> etoii(n-1, { -1, -1 }), dlst;
	wlst.reserve(n*2-2);
	dlst.reserve(n*2-2);
	auto dfs = [&](auto dfs, int di=0, int vi=0, int pi=-1) -> void {
		for (const auto& tpi : g[vi]) if (tpi.first != pi) {
			int ti = tpi.first, ei = tpi.second, wi = w[ei];
			chmin(vtoi[vi], (int)(dlst.size()));
			dlst.emplace_back(di, (int)(dlst.size()));
			etoii[ei].first = wlst.size();
			wlst.push_back(wi);
			dfs(dfs, di+1, ti, vi);
			chmin(vtoi[ti], (int)(dlst.size()));
			dlst.emplace_back(di+1, (int)(dlst.size()));
			etoii[ei].second = wlst.size();
			wlst.push_back(-wi);
		}
	};
	dfs(dfs);
	fenwick_tree<ll> ft(n*2-2);
	rep(i, n*2-2) ft.add(i, wlst[i]);
	segtree<S, op, e> seg(dlst);
	cin >> q;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int id, wi;
			cin >> id >> wi;
			--id;
			ft.add(etoii[id].first, -w[id]+wi);
			ft.add(etoii[id].second, w[id]-wi);
			w[id] = wi;
		}
		else {
			int ui, vi;
			cin >> ui >> vi;
			--ui; --vi;
			if (ui == vi) {
				cout << 0 << endl;
				continue;
			}
			int li = min(vtoi[ui], vtoi[vi]), ri = max(vtoi[ui], vtoi[vi]), ci = seg.prod(li, ri+1).second;
			ll res = ft.sum(0, li) + ft.sum(0, ri) - ft.sum(0, ci) * 2;
			cout << res << endl;
		}
	}
	return 0;
}
