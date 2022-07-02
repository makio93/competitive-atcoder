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
	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	vector<string> b(n*3);
	rep(i, n*3) rep(j, 3) b[i] += a[i%n];
	ll res = 0;
	rep(i, n) rep(j, n) {
		rep3(dy, -1, 2) rep3(dx, -1, 2) if (dy!=0 || dx!=0) {
			int y = n+i, x = n+j;
			string str = (string)("") + b[y][x];
			rep(i2, n-1) {
				y += dy;
				x += dx;
				str += b[y][x];
			}
			res = max(res, stoll(str));
		}
	}
	cout << res << endl;
	return 0;
}
