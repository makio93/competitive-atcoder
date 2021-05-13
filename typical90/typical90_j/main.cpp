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

int main() {
	int n, q;
	cin >> n;
	vector<int> c(n), p(n);
	rep(i, n) {
		cin >> c[i] >> p[i];
		c[i]--;
	}
	vector<vector<int>> sum(n+1, vector<int>(2));
	rep(i, n) rep(j, 2) {
		if (c[i] == j) sum[i+1][j] = sum[i][j] + p[i];
		else sum[i+1][j] = sum[i][j];
	}
	cin >> q;
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li;
		cout << (sum[ri][0]-sum[li][0]) << ' ' << (sum[ri][1]-sum[li][1]) << endl;
	}
	return 0;
}
