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

// 自力AC

int main() {
	int h, w, q;
	cin >> h >> w >> q;
	dsu d(h*w);
	vector<bool> red(h*w);
	rep(i, q) {
		int ti;
		cin >> ti;
		if (ti == 1) {
			int ri, ci;
			cin >> ri >> ci;
			--ri; --ci;
			int vi = ri * w + ci;
			red[vi] = true;
			const vector<int> dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
			rep(j, 4) {
				int nr = ri + dr[j], nc = ci + dc[j];
				if (nr<0 || nr>=h || nc<0 || nc>=w) continue;
				int ni = nr * w + nc;
				if (red[ni]) d.merge(ni, vi);
			}
		}
		else {
			int ri1, ci1, ri2, ci2;
			cin >> ri1 >> ci1 >> ri2 >> ci2;
			--ri1; --ci1; --ri2; --ci2;
			int v1 = ri1 * w + ci1, v2 = ri2 * w + ci2;
			if (v1 == v2) {
				if (red[v1]) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
			else {
				if (d.same(v1, v2)) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
	}
	return 0;
}
