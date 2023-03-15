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
const string dir = "RLUD";
const vector<int> dx = { 1, -1, 0, 0 }, dy = { 0, 0, 1, -1 };

int main() {
	int n;
	string s;
	cin >> n >> s;
	int x = 0, y = 0;
	vector<pair<int, int>> plst;
	plst.emplace_back(x, y);
	rep(i, n) {
		int di = dir.find(s[i]);
		x += dx[di]; y += dy[di];
		plst.emplace_back(x, y);
	}
	sort(all(plst));
	plst.erase(unique(all(plst)), plst.end());
	if ((int)(plst.size()) < n+1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
