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
const vector<int> dy = { -1, -1, 0, 1, 1, 1, 0, -1 }, dx = { 0, 1, 1, 1, 0, -1, -1, -1 };
const string tar = "snuke";

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	function<vector<pair<int,int>>(int,int,int)> check = [&](int yi, int xi, int di) {
		vector<pair<int, int>> rlst;
		rep(i1, 5) {
			if (yi<0 || yi>=h || xi<0 || xi>=w || s[yi][xi]!=tar[i1]) return vector<pair<int, int>>();
			rlst.emplace_back(yi, xi);
			yi += dy[di], xi += dx[di];
		}
		return rlst;
	};
	vector<pair<int, int>> res;
	rep(i, h) {
		rep(j, w) {
			rep(k, 8) {
				res = check(i, j, k);
				if (!res.empty()) break;
			}
			if (!res.empty()) break;
		}
		if (!res.empty()) break;
	}
	rep(i, 5) cout << (res[i].first+1) << ' ' << (res[i].second+1) << endl;
	return 0;
}
