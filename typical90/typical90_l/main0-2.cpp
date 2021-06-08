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

// 自力AC、ACLを使わず

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

int main() {
	int h, w, q;
	cin >> h >> w >> q;
	UnionFind uf(h*w);
	vector<bool> red(h*w);
	rep(i, q) {
		int ti;
		cin >> ti;
		if (ti == 1) {
			int ri, ci;
			cin >> ri >> ci;
			--ri; --ci;
			int vi = ri * w + ci;
			red[vi] = true;
			const vector<int> dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
			rep(j, 4) {
				int nr = ri + dr[j], nc = ci + dc[j];
				if (nr<0 || nr>=h || nc<0 || nc>=w) continue;
				int ni = nr * w + nc;
				if (red[ni] && !uf.same(ni, vi)) uf.unite(ni, vi);
			}
		}
		else {
			int ri1, ci1, ri2, ci2;
			cin >> ri1 >> ci1 >> ri2 >> ci2;
			--ri1; --ci1; --ri2; --ci2;
			int v1 = ri1 * w + ci1, v2 = ri2 * w + ci2;
			if (red[v1] && red[v2] && uf.same(v1, v2)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
