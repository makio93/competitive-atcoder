// 本番TLE

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
	int n;
	cin >> n;
	vector<int> x1(n), y1(n), z1(n), x2(n), y2(n), z2(n);
	rep(i, n) cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];
	function<bool(int, int, int, int, int, int, int, int)> check = [](int a11, int b11, int a12, int b12, int a21, int b21, int a22, int b22) {
		return !(a12 <= a21 || a22 <= a11 || b12 <= b21 || b22 <= b11);
	};
	rep(i, n) {
		int res = 0;
		rep(j, n) if (j != i) {
			bool ok = false;
			if (x1[i] == x1[j] || x1[i] == x2[j] || x2[i] == x1[j] || x2[i] == x2[j]) {
				if (check(y1[i], z1[i], y2[i], z2[i], y1[j], z1[j], y2[j], z2[j])) ok = true;
			}
			if (y1[i] == y1[j] || y1[i] == y2[j] || y2[i] == y1[j] || y2[i] == y2[j]) {
				if (check(x1[i], z1[i], x2[i], z2[i], x1[j], z1[j], x2[j], z2[j])) ok = true;
			}
			if (z1[i] == z1[j] || z1[i] == z2[j] || z2[i] == z1[j] || z2[i] == z2[j]) {
				if (check(x1[i], y1[i], x2[i], y2[i], x1[j], y1[j], x2[j], y2[j])) ok = true;
			}
			if (ok) ++res;
		}
		cout << res << endl;
	}
	return 0;
}
