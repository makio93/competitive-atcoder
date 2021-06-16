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

// 自力AC

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

template<typename T>
struct BIT {
	int n;
	vector<T> d;
	BIT(int n=0):n(n),d(n+1) {}
	void add(int i, T x=1) {
		for (i++; i <= n; i += i&-i) {
			d[i] += x;
		}
	}
	T sum(int i) {
		T x = 0;
		for (i++; i; i -= i&-i) {
			x += d[i];
		}
		return x;
	}
	T sum(int l, int r) {
		return sum(r-1) - sum(l-1);
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	UnionFind u(n);
	BIT<ll> s1(n), s2(n);
	rep(i, q) {
		int ti, xi, yi; ll vi;
		cin >> ti >> xi >> yi >> vi;
		if (ti == 0) {
			u.unite(xi-1, yi-1);
			if (xi%2 == 1) {
				ll val = s1.sum(xi, xi+1);
				s1.add(xi, vi-val);
			}
			else {
				ll val = s2.sum(xi, xi+1);
				s2.add(xi, vi-val);
			}
		}
		else {
			if (yi == xi) cout << vi << endl;
			else {
				if (u.same(xi-1, yi-1)) {
					if (yi > xi) {
						ll sum1 = s1.sum(xi, yi), sum2 = s2.sum(xi, yi);
						if ((yi-1)%2 == 1) {
							ll res = sum1 - sum2;
							if ((yi-xi)%2 == 0) res += vi;
							else res -= vi;
							cout << res << endl;
						}
						else {
							ll res = sum2 - sum1;
							if ((yi-xi)%2 == 0) res += vi;
							else res -= vi;
							cout << res << endl;
						}
					}
					else {
						ll sum1 = s1.sum(yi, xi), sum2 = s2.sum(yi, xi);
						if (yi%2 == 1) {
							ll res = sum1 - sum2;
							if ((xi-yi)%2 == 0) res += vi;
							else res -= vi;
							cout << res << endl;
						}
						else {
							ll res = sum2 - sum1;
							if ((xi-yi)%2 == 0) res += vi;
							else res -= vi;
							cout << res << endl;
						}
					}
				}
				else cout << "Ambiguous" << endl;
			}
		}
	}
	return 0;
}
