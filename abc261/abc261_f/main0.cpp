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

struct BIT {
	int n;
	vector<int> d;
	BIT(int n=0) : n(n), d(n+1) {}
	void add(int i, int x=1) {
		for (i++; i<=n; i+=i&-i) {
			d[i] += x;
		}
	}
	int sum(int i) {
		int x = 0;
		for (i++; i; i-=i&-i) {
			x += d[i];
		}
		return x;
	}
	int sum(int l, int r) {
		return sum(r-1) - sum(l-1);
	}
};

struct MBIT {
	int n;
	vector<unordered_map<int, int>> d;
	MBIT(int n=0) : n(n), d(n+1) {}
	void add(int i, int c, int x=1) {
		for (i++; i<=n; i+=i&-i) {
			d[i][c] += x;
			if (d[i][c] == 0) d[i].erase(c);
		}
	}
	int sum(int i, int c) {
		int x = 0;
		for (i++; i; i-=i&-i) {
			if (d[i].find(c) != d[i].end()) x += d[i][c];
		}
		return x;
	}
	int sum(int l, int r, int c) {
		return sum(r-1, c) - sum(l-1, c);
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> c(n), x(n);
	rep(i, n) cin >> c[i];
	rep(i, n) cin >> x[i];
	BIT abit(n+2);
	MBIT bbit(n+2);
	ll res = 0;
	repr(i, n) {
		res += abit.sum(0, x[i]) - bbit.sum(0, x[i], c[i]);
		abit.add(x[i], 1);
		bbit.add(x[i], c[i], 1);
	}
	cout << res << endl;
	return 0;
}
