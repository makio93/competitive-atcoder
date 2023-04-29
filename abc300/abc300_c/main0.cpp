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
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	int n = min(h, w);
	vector<int> s(n);
	auto check = [&](int yi, int xi) -> int {
		int di = 0;
		while (yi-di-1>=0 && yi+di+1<h && xi-di-1>=0 && xi+di+1<w) {
			if (c[yi-di-1][xi-di-1]!='#' || c[yi-di-1][xi+di+1]!='#' || c[yi+di+1][xi-di-1]!='#' || c[yi+di+1][xi+di+1]!='#') return di;
			++di;
			c[yi-di][xi-di] = c[yi-di][xi+di] = c[yi+di][xi-di] = c[yi+di][xi+di] = '.';
		}
		return di;
	};
	auto center = [&](int yi, int xi) -> bool {
		if (yi-1<0 || yi+1>=h || xi-1<0 || xi+1>=w) return false;
		return c[yi-1][xi-1]=='#' && c[yi-1][xi+1]=='#' && c[yi+1][xi-1]=='#' && c[yi+1][xi+1]=='#' && c[yi][xi]=='#';
	};
	bool fin = false;
	while (!fin) {
		fin = true;
		rep(i, h) {
			rep(j, w) if (center(i, j)) {
				fin = false;
				int val = check(i, j);
				s[val-1]++;
				break;
			}
			if (!fin) break;
		}
	}
	rep(i, n) cout << s[i] << (i<n-1?' ':'\n');
	return 0;
}
