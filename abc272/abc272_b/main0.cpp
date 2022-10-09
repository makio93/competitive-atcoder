// バチャ本番AC

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
	int n, m;
	cin >> n >> m;
	vector<int> k(m);
	vector<vector<int>> x(m);
	rep(i, m) {
		cin >> k[i];
		rep(j, k[i]) {
			int xi;
			cin >> xi;
			--xi;
			x[i].push_back(xi);
		}
	}
	vector<vector<bool>> used(n, vector<bool>(n));
	rep(i, n) used[i][i] = true;
	rep(i, m) rep(j1, k[i]) rep3(j2, j1+1, k[i]) used[x[i][j1]][x[i][j2]] = used[x[i][j2]][x[i][j1]] = true;
	bool ok = true;
	rep(i, n) if (find(all(used[i]), false) != used[i].end()) {
		ok = false;
		break;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
