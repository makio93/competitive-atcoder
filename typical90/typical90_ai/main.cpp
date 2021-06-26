#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力で解答、分からない

vector<vector<int>> g;
vector<pair<int, int>> vs;
vector<int> depth;

struct SegmentTree {
	int n;
	vector<pair<int, int>> dat;
	SegmentTree() { init(1); }
	SegmentTree(int n_) { init(n_); }
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat = vector<pair<int, int>>(2*n-1, { (int)(1e9), (int)(1e9) });
	}
	void update(int k, int a) {
		int tk = k;
		k += n-1;
		dat[k] = { a, tk };
		while (k > 0) {
			k = (k-1) / 2;
			dat[k] = min(dat[k*2+1], dat[k*2+2]);
		}
	}
	pair<int, int> query(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) { r = n; k = 0; l = 0; }
		if (r<=a || b<=l) return { (int)(1e9), (int)(1e9) };
		if (a<=l && r<=b) return dat[k];
		else {
			pair<int, int> vl = query(a, b, k*2+1, l, (l+r)/2);
			pair<int, int> vr = query(a, b, k*2+2, (l+r)/2, r);
			return min(vl, vr);
		}
	}
};

void dfs(int v=0, int p=-1, int d=0) {
	vs.emplace_back(v, 0);
	depth[v] = d;
	for (int t : g[v]) if (t != p) dfs(t, v, d+1);
	vs.emplace_back(v, 1);
}

int main() {
	int n, q;
	cin >> n;
	g = vector<vector<int>>(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	depth = vector<int>(n, -1);
	vs = vector<pair<int, int>>();
	dfs();
	vector<int> fid(n, -1), sid(n, -1);
	int len = vs.size();
	rep(i, len) {
		if (vs[i].second == 0) fid[vs[i].first] = i;
		else sid[vs[i].first] = i;
	}
	SegmentTree st(len+5);
	rep(i, len) st.update(i, depth[vs[i].first]);
	cin >> q;
	rep(i, q) {
		int ki;
		cin >> ki;
		set<int> fvl, svl, tl;
		rep(j, ki) {
			int vi;
			cin >> vi;
			--vi;
			fvl.insert(fid[vi]);
			svl.insert(sid[vi]);
			tl.insert(fid[vi]);
			tl.insert(sid[vi]);
		}
		int li = (*svl.begin()), ri = (*fvl.rbegin());
		if (ri-li < 0) swap(ri, li);
		auto aid = st.query(li, ri+1);
		int ai = aid.second, tsub = 0, j = li;
		while (j <= ai) {
			if (vs[j].second == 0) {
				int j2 = sid[vs[j].first];
				if (tl.lower_bound(j2) == tl.lower_bound(j+1)) {
					tsub += (j2 - j) / 2 - 1;
					j = j2 + 1;
				}
				else ++j;
			}
			else ++j;
		}
		j = ri;
		while (j >= ai) {
			if (vs[j].second == 1) {
				int j2 = fid[vs[j].first];
				if (tl.lower_bound(j2+1) == tl.lower_bound(j)) {
					tsub += (j - j2) / 2 - 1;
					j = j2 - 1;
				}
				else --j;
			}
			else --j;
		}
		int res = ri - li - tsub + 1;
		cout << res << endl;
	}
	return 0;
}
