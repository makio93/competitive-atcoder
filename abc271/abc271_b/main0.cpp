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

const int INF = (int)(1e9);

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> l(n);
	vector<vector<int>> a(n);
	rep(i, n) {
		cin >> l[i];
		a[i].resize(l[i]);
		rep(j, l[i]) cin >> a[i][j];
	}
	rep(i, q) {
		int si, ti;
		cin >> si >> ti;
		--si; --ti;
		cout << a[si][ti] << endl;
	}
	return 0;
}
