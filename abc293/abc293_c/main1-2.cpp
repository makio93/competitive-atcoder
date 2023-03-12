// 解説AC2

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
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	vector<int> perm(h+w-2);
	rep(i, w-1) perm[h+w-3-i] = 1;
	int res = 0;
	do {
		unordered_set<int> ast;
		int yi = 0, xi = 0;
		ast.insert(a[yi][xi]);
		bool ok = true;
		rep(i, h+w-2) {
			if (perm[i] == 1) ++xi;
			else ++yi;
			if (ast.find(a[yi][xi]) != ast.end()) ok = false;
			else ast.insert(a[yi][xi]);
		}
		if (ok) ++res;
	} while (next_permutation(all(perm)));
	cout << res << endl;
	return 0;
}
