// 学習1回目,自力AC

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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> p(n, vector<int>(3));
	rep(i, n) rep(j, 3) cin >> p[i][j];
	vector<int> psum(n), plst;
	rep(i, n) rep(j, 3) psum[i] += p[i][j];
	plst = psum;
	sort(all(plst));
	rep(i, n) {
		int id = upper_bound(all(plst), psum[i]+300) - plst.begin();
		if (n-id <= k-1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
