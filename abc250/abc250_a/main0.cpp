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
	int h, w, r, c;
	cin >> h >> w >> r >> c;
	--r; --c;
	vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
	int res = 0;
	rep(i, 4) {
		int ny = r + dy[i], nx = c + dx[i];
		if (ny>=0 && ny<h && nx>=0 && nx<w) ++res;
	}
	cout << res << endl;
	return 0;
}
