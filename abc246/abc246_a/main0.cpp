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
	unordered_map<int, int> xval, yval;
	rep(i, 3) {
		int xi, yi;
		cin >> xi >> yi;
		xval[xi]++;
		yval[yi]++;
	}
	int xres = 0, yres = 0;
	for (auto pi : xval) if (pi.second == 1) xres = pi.first;
	for (auto pi : yval) if (pi.second == 1) yres = pi.first;
	cout << xres << ' ' << yres << endl;
	return 0;
}
