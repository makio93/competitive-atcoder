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

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> p(n, vector<int>(3));
	rep(i, n) rep(j, 3) cin >> p[i][j];
	vector<int> sum(n), rank;
	rep(i, n) rep(j, 3) sum[i] += p[i][j];
	rank = sum;
	sort(all(rank));
	rep(i, n) {
		int di = upper_bound(all(rank), sum[i]+300) - rank.begin();
		if ((n-di+1) <= k) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
