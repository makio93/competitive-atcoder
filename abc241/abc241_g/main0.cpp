// 本番,WA

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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(n, -1));
	rep(i, n) b[i][i] = 0;
	rep(i, m) {
		int wi, li;
		cin >> wi >> li;
		--wi; --li;
		b[wi][li] = 1;
		b[li][wi] = 0;
	}
	vector<int> res;
	rep(i, n) {
		auto a = b;
		rep(j, n) if (a[i][j] == -1) {
			a[i][j] = 1;
			a[j][i] = 0;
		}
		int cnt = 0;
		rep(j, n) if (a[i][j] == 1) ++cnt;
		bool ok = true;
		rep(i2, n) if (i2 != i) {
			int ncnt = 0;
			rep(j, n) if (a[i2][j] == 1) ++ncnt;
			rep(j, n) if (a[i2][j] == -1) {
				if (ncnt+1 < cnt) {
					a[i2][j] = 1;
					a[j][i2] = 0;
					++ncnt;
				}
				else {
					a[i2][j] = 0;
					a[j][i2] = 1;
				}
			}
			if (ncnt >= cnt) {
				ok = false;
				break;
			}
		}
		if (ok) res.push_back(i+1);
	}
	int rlen = res.size();
	if (rlen > 0) rep(i, rlen) printf("%d%c", res[i], (i<rlen-1?' ':'\n'));
	else cout << endl;
	return 0;
}
