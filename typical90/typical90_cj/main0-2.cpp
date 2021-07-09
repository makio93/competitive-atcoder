#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力その2、やはり解けない

struct UnionFind {
	vector<int> d;
	UnionFind(int n=0): d(n, -1) {}
	int find(int x) {
		if (d[x] < 0) return x;
		return (d[x] = find(d[x]));
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (d[x] > d[y]) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) { return (find(x) == find(y)); }
	int size(int x) { return -d[find(x)]; }
};

int n;
vector<int> a;
UnionFind uf;
vector<set<int>> res;
vector<vector<int>> g;
vector<int> visited;

bool scheck(set<int>& s1, set<int>& s2) {
	for (int si : s2) for (int si1 : s1) if (si1!=si && uf.same(si1, si)) return false;
	return true;
}

void smerge(set<int>& s1, set<int>& s2) {
	for (int si : s2) s1.insert(si);
}

bool dfs(map<int, set<int>>& m, int v) {
	visited[v] = 0;
	bool one = true;
	for (int t : g[v]) if (visited[t] == 1) one = false;
	for (int t : g[v]) if (visited[t] == -1) {
		map<int, set<int>> m2;
		m2[0] = {};
		bool vres = dfs(m2, t);
		if (vres) return true;
		for (auto itr=m.rbegin(); itr!=m.rend(); ++itr) {
			for (auto mp2 : m2) if (mp2.first != 0) {
				int nc = (itr->first + mp2.first);
				auto si = itr->second;
				bool sok = scheck(si, mp2.second);
				if (sok) {
					smerge(si, mp2.second);
					if (m.find(nc)!=m.end() && m[nc]!=si) {
						res.push_back(m[nc]);
						res.push_back(si);
						return true;
					}
					m[nc] = si;
				}
			}
		}
		if (one) {
			visited[v] = 1;
			m2.clear();
			m2[0] = {};
			m2[a[v]] = { v };
			bool vres = dfs(m2, t);
			if (vres) return true;
			for (auto itr=m.rbegin(); itr!=m.rend(); ++itr) {
				for (auto mp2 : m2) if (mp2.first != 0) {
					int nc = (itr->first + mp2.first);
					auto si = itr->second;
					bool sok = scheck(si, mp2.second);
					if (sok) {
						smerge(si, mp2.second);
						if (m.find(nc)!=m.end() && m[nc]!=si) {
							res.push_back(m[nc]);
							res.push_back(si);
							return true;
						}
						m[nc] = si;
					}

				}
			}
			visited[v] = 0;
		}
	}
	visited[v] = -1;
	return false;
}

int main() {
	int q;
	cin >> n >> q;
	a = vector<int>(n);
	rep(i, n) cin >> a[i];
	int sum = 0;
	rep(i, n) sum += a[i];
	g = vector<vector<int>>(n);
	uf = UnionFind(n);
	rep(i, q) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		g[xi].push_back(yi);
		g[yi].push_back(xi);
		uf.unite(xi, yi);
	}
	set<int> us;
	rep(i, n) {
		int gi = uf.find(i);
		if (us.find(gi) == us.end()) us.insert(gi);
	}
	res = vector<set<int>>();
	visited = vector<int>(n, -1);
	map<int, set<int>> m;
	m[0] = {};
	for (int gi : us) {
		map<int, set<int>> m1;
		m1[0] = {};
		bool vres = dfs(m1, gi);
		if (vres) break;
		bool br = false;
		for (auto itr=m.rbegin(); itr!=m.rend(); ++itr) {
			for (auto mp2 : m1) if (mp2.first != 0) {
				int nc = (itr->first + mp2.first);
				auto si = itr->second;
				bool sok = scheck(si, mp2.second);
				if (sok) {
					smerge(si, mp2.second);
					if (m.find(nc)!=m.end() && m[nc]!=si) {
						res.push_back(m[nc]);
						res.push_back(si);
						br = true;
						break;
					}
					m[nc] = si;
				}
				if (br) break;
			}
			if (br) break;
		}
		if (br) break;
	}
	rep(i1, 2) {
		int rlen = (int)(res[i1].size());
		cout << rlen << endl;
		int rid = 0;
		for (int ri : res[i1]) {
			printf("%d%c", ri+1, (rid<rlen-1?' ':'\n'));
			++rid;
		}
	}
	return 0;
}
