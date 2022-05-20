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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(m));
	rep(i, n) rep(j, m) cin >> b[i][j];
	bool ok = true;
	rep(i, m-1) if (b[0][i+1]-b[0][i] != 1) ok = false;
	rep(i, m-1) if (b[0][i]%7==0 && b[0][i+1]%7==1) ok = false;
	if (!ok) {
		cout << "No" << endl;
		return 0;
	}
	rep3(i, 1, n) rep(j, m) if (b[i][j]-b[0][j] != 7*i) ok = false;
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
