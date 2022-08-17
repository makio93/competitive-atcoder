// 

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
	int n, k;
	cin >> n >> k;
	vector<string> c(n);
	rep(i, n) cin >> c[i];
	unordered_map<int, int> vids;
	rep(i1, k) {
		int cnt = 0;
		rep(i, n) rep(j, n) if (c[i][j] == (char)('1'+i1)) {
			vids[i*n+j] = i1 * 100 + cnt;
			++cnt;
		}
	}
	vector<int> ord(k);
	iota(all(ord), 0);
	pair<int, vector<tuple<int, int, int, int>>> res = { -1, vector<tuple<int, int, int, int>>() };
	do {
		rep(bi, 1<<k) {
			vector<vector<bool>> used(n, vector<bool>(n));
			vector<tuple<int, int, int, int>> rlst;
			bool ful = false;
			dsu glst(k*100);
			rep(i1, k) {
				auto rsearch = [&]() -> void {
					if (ful) return;
					rep(i, n) {
						int li = -1;
						rep(j, n) {
							if (c[i][j] == '0') {
								if (used[i][j] && li!=-1) li = -1;
							}
							else if (c[i][j] == (char)('1'+ord[i1])) {
								if (li != -1) {
									if (!glst.same(vids[i*n+li], vids[i*n+j])) {
										rlst.emplace_back(i, li, i, j);
										glst.merge(vids[i*n+li], vids[i*n+j]);
										rep3(i2, li+1, j) used[i][i2] = true;
										if ((int)(rlst.size()) >= k*100) {
											ful = true;
											return;
										}
									}
								}
								li = j;
							}
							else li = -1;
						}
					}
				};
				auto csearch = [&]() -> void {
					if (ful) return;
					rep(i, n) {
						int ui = -1;
						rep(j, n) {
							if (c[j][i] == '0') {
								if (used[j][i] && ui!=-1) ui = -1;
							}
							else if (c[j][i] == (char)('1'+ord[i1])) {
								if (ui != -1) {
									if (!glst.same(vids[ui*n+i], vids[j*n+i])) {
										rlst.emplace_back(ui, i, j, i);
										rep3(i2, ui+1, j) used[i2][i] = true;
										if ((int)(rlst.size()) >= k*100) {
											ful = true;
											return;
										}
									}
								}
								ui = j;
							}
							else ui = -1;
						}
					}
				};
				if (!((bi>>i1)&1)) {
					rsearch();
					csearch();
				}
				else {
					csearch();
					rsearch();
				}
				if (ful) break;
			}
			auto nlst = glst.groups();
			int sco = 0;
			for (auto& vi : nlst) if ((int)(vi.size()) > 1) {
				int len = vi.size();
				sco += len * (len-1) / 2;
			}
			res = max(res, { sco, rlst });
		}
	} while (next_permutation(all(ord)));
	cout << 0 << endl;
	int y = res.second.size();
	cout << y << endl;
	rep(i, y) cout << get<0>(res.second[i]) << ' ' << get<1>(res.second[i]) << ' ' << get<2>(res.second[i]) << ' ' << get<3>(res.second[i]) << endl;
	return 0;
}
