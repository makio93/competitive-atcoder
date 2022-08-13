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
	int h1, w1, h2, w2;
	cin >> h1 >> w1;
	vector<vector<int>> a(h1, vector<int>(w1));
	rep(i, h1) rep(j, w1) cin >> a[i][j];
	cin >> h2 >> w2;
	vector<vector<int>> b(h2, vector<int>(w2));
	rep(i, h2) rep(j, w2) cin >> b[i][j];
	vector<int> hid(h2, -1), wid(w2, -1);
	auto wdfs = [&](auto wdfs, int di=0, int vi=0) -> bool {
		if (di == w2) {
			rep(i1, h2) rep(j1, w2) if (a[hid[i1]][wid[j1]] != b[i1][j1]) return false;
			return true;
		}
		for (int i1=vi; i1+(w2-di)<=w1; ++i1) {
			wid[di] = i1;
			if (wdfs(wdfs, di+1, i1+1)) return true;
		}
		return false;
	};
	auto hdfs = [&](auto hdfs, int di=0, int vi=0) -> bool {
		if (di == h2) return wdfs(wdfs);
		for (int i1=vi; i1+(h2-di)<=h1; ++i1) {
			hid[di] = i1;
			if (hdfs(hdfs, di+1, i1+1)) return true;
		}
		return false;
	};
	if (hdfs(hdfs)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
