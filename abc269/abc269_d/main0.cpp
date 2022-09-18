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

const vector<int> dy = { -1, -1, 0, 0, 1, 1 }, dx = { -1, 0, -1, 1, 0, 1 };

int main() {
	int n;
	cin >> n;
	map<pair<int, int>, int> xy;
	rep(i, n) {
		int xi, yi;
		cin >> xi >> yi;
		xy[{xi, yi}] = 0;
	}
	int res = 0;
	for (auto& pi : xy) if (pi.second == 0) {
		++res;
		queue<pair<int, int>> que;
		que.emplace(pi.first.first, pi.first.second);
		xy[pi.first] = res;
		while (!que.empty()) {
			auto vpi = que.front(); que.pop();
			int xi = vpi.first, yi = vpi.second;
			rep(i2, 6) {
				int nxi = xi + dx[i2], nyi = yi + dy[i2];
				if (xy.find({nxi,nyi})==xy.end() || xy[{nxi,nyi}]!=0) continue;
				xy[{nxi, nyi}] = res;
				que.emplace(nxi, nyi); 
			}
		}
	}
	cout << res << endl;
	return 0;
}
