// 自力AC,ヒント有り

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
	cin >> n;
	vector<int> c(n);
	rep(i, n) {
		cin >> c[i];
		c[i]--;
	}
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> in(n), out(n), ord, gcnt(n), par(n);
	auto dfs0 = [&](auto dfs0, int vi=0, int pi=-1, int id=0) -> int {
		in[vi] = id;
		ord.push_back(vi);
		par[vi] = pi;
		gcnt[vi]++;
		for (const auto& ti : g[vi]) if (ti != pi) {
			id = dfs0(dfs0, ti, vi, id+1);
			gcnt[vi] += gcnt[ti];
		}
		out[vi] = id+1;
		return id+1;
	};
	dfs0(dfs0);
	vector<vector<int>> cv(n);
	rep(i, n) cv[c[ord[i]]].push_back(ord[i]);
	vector<vector<int>> ng(n);
	auto ispar = [&](int pi, int vi) -> bool {
		return in[vi] > in[pi] && out[vi] < out[pi];
	};
	vector<ll> res(n);
	rep(i, n) if (!cv[i].empty()) {
		vector<int> vlst;
		vlst.push_back(0);
		for (const int& vi : cv[i]) {
			vlst.push_back(vi);
			for (const int& ti : g[vi]) if (ti != par[vi]) vlst.push_back(ti);
		}
		sort(all(vlst), [&](int li, int ri) -> bool {
			return in[li] < in[ri];
		});
		vlst.erase(unique(all(vlst)), vlst.end());
		stack<int> st;
		for (const int& vi : vlst) {
			while (!st.empty() && !ispar(st.top(), vi)) st.pop();
			if (!st.empty()) ng[st.top()].push_back(vi);
			st.push(vi);
		}
		auto dfs1 = [&](auto dfs1, int ci, int vi=0) -> ll {
			ll rval = 0;
			for (const int& ti : ng[vi]) rval += dfs1(dfs1, ci, ti);
			if (c[vi] == ci) {
				rval += gcnt[vi];
				int vsum = 0;
				for (const int& ti : ng[vi]) {
					rval += (ll)vsum * gcnt[ti];
					vsum += gcnt[ti];
				}
			}
			else {
				int vsum = gcnt[vi];
				for (const int& ti : ng[vi]) vsum -= gcnt[ti];
				for (const int& ti : ng[vi]) {
					rval += (ll)vsum * gcnt[ti];
					vsum += gcnt[ti];
				}
			}
			return rval;
		};
		res[i] += dfs1(dfs1, i);
		for (const int& vi : vlst) ng[vi].clear();
	}
	rep(i, n) cout << res[i] << endl;
	return 0;
}
