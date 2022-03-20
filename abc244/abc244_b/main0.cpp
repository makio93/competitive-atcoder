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
	int n;
	string t;
	cin >> n >> t;
	const vector<int> dy = { 0, -1, 0, 1 }, dx = { 1, 0, -1, 0 };
	int di = 0, y = 0, x = 0;
	rep(i, n) {
		if (t[i] == 'S') {
			y += dy[di]; x += dx[di];
		}
		else di = (di+1) % 4;
	}
	cout << x << ' ' << y << endl;
	return 0;
}
