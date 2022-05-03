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
	vector<vector<bool>> xy(n, vector<bool>(n));
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		xy[xi][yi] = xy[yi][xi] = true;
	}
	int res = 0;
	rep3(i, 1, (1<<n)) {
		vector<int> mlst;
		rep(j, n) if ((i>>j)&1) mlst.push_back(j);
		int mlen = mlst.size();
		bool ok = true;
		rep(i2, mlen) rep3(j2, i2+1, mlen) if (!xy[mlst[i2]][mlst[j2]]) ok = false;
		if (ok) res = max(res, __builtin_popcount(i));
	}
	cout << res << endl;
	return 0;
}
