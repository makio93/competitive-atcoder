// 自力AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const string tar = "JOI";

template<typename T>
struct BIT {
	int m, n;
	vector<vector<T>> d;
	BIT(int m=0, int n=0) : m(m), n(n), d(m+1, vector<T>(n+1)) {}
	void add(int i, int j, T x=1) {
		for (i++; i<=m; i+=i&-i) {
			int tj = j;
			for (tj++; tj<=n; tj+=tj&-tj) d[i][tj] += x;
		}
	}
	T sum(int i, int j) {
		T x = 0;
		for (i++; i; i-=i&-i) {
			int tj = j;
			for (tj++; tj; tj-=tj&-tj) x += d[i][tj];
		}
		return x;
	}
	T sum(int u, int l, int d, int r) {
		return sum(d-1, r-1) - sum(u-1, r-1) - sum(d-1, l-1) + sum(u-1, l-1);
	}
};

int main() {
	int m, n, k;
	cin >> m >> n >> k;
	vector<string> s(m);
	rep(i, m) cin >> s[i];
	vector<int> a(k), b(k), c(k), d(k);
	rep(i, k) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--; b[i]--;
	}
	vector<BIT<int>> scnt(3, BIT<int>(m, n));
	rep(i, m) rep(j, n) rep(i2, 3) if (s[i][j] == tar[i2]) scnt[i2].add(i, j, 1);
	rep(i, k) rep(j, 3) cout << scnt[j].sum(a[i], b[i], c[i], d[i]) << (j<2?' ':'\n');
	return 0;
}
