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
	vector<string> p1(4), p2(4), p3(4);
	rep(i, 4) cin >> p1[i];
	rep(i, 4) cin >> p2[i];
	rep(i, 4) cin >> p3[i];
	int cnt = 0;
	rep(i, 4) rep(j, 4) if (p1[i][j] == '#') ++cnt;
	rep(i, 4) rep(j, 4) if (p2[i][j] == '#') ++cnt;
	rep(i, 4) rep(j, 4) if (p3[i][j] == '#') ++cnt;
	if (cnt != 16) {
		cout << "No" << endl;
		return 0;
	}
	function<void(vector<string>&)> roll = [](vector<string>& p) {
		vector<string> tmp(4, string(4, '.'));
		rep(i, 4) rep(j, 4) tmp[i][j] = p[j][3-i];
		p.assign(4, string(4, '.'));
		int ui = 4, li = 4;
		rep(i, 4) rep(j, 4) if (tmp[i][j] == '#') ui = min(ui, i), li = min(li, j);
		rep3(i, ui, 4) rep3(j, li, 4) p[i-ui][j-li] = tmp[i][j];
	};
	bool ok = false;
	vector<vector<bool>> b(4, vector<bool>(4));
	function<bool(vector<string>&, int, int)> check = [&](vector<string>& p, int ui, int li) {
		rep(i, 4) rep(j, 4) if (p[i][j] == '#' && (i+ui>=4 || j+li>=4 || b[i+ui][j+li])) return false;
		return true;
	};
	function<void(vector<string>&, int, int)> write = [&](vector<string>& p, int ui, int li) {
		rep(i, 4) rep(j, 4) if (p[i][j] == '#') b[i+ui][j+li] = true;
	};
	function<void(vector<string>&, int, int)> remove = [&](vector<string>& p, int ui, int li) {
		rep(i, 4) rep(j, 4) if (p[i][j] == '#') b[i+ui][j+li] = false;
	};
	rep(i1, 4) {
		roll(p1);
		rep(i2, 4) rep(i3, 4) {
			if (!check(p1, i2, i3)) continue;
			write(p1, i2, i3);
			rep(j1, 4) {
				roll(p2);
				rep(j2, 4) rep(j3, 4) {
					if (!check(p2, j2, j3)) continue;
					write(p2, j2, j3);
					rep(k1, 4) {
						roll(p3);
						rep(k2, 4) rep(k3, 4) {
							if (!check(p3, k2, k3)) continue;
							ok = true;
						}
					}
					remove(p2, j2, j3);
				}
			}
			remove(p1, i2, i3);
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
