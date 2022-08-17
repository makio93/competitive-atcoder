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

clock_t start = clock();

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
	tuple<int, vector<tuple<int, int, int, int>>, pair<vector<int>, int>> res = { -INF, vector<tuple<int, int, int, int>>(), { vector<int>(), -1 } };
	do {
		rep(bi, 2) {
			vector<vector<bool>> used(n, vector<bool>(n));
			vector<tuple<int, int, int, int>> rlst;
			bool ful = false;
			dsu glst(k*100);
			auto rsearch = [&](int i1) -> void {
				if (ful) return;
				int pi1 = min(k-1, i1+(i1%2==0?1:0));
				rep(i, n) {
					int li = -1, pli = -1;
					rep(j, n) {
						if (c[i][j] == '0') {
							if (used[i][j] && li!=-1) li = pli = -1;
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
								if (pli != -1) {
									if (!glst.same(vids[i*n+pli], vids[i*n+li])) {
										rlst.emplace_back(i, pli, i, li);
										glst.merge(vids[i*n+pli], vids[i*n+li]);
										rep3(i2, pli+1, li) used[i][i2] = true;
										if ((int)(rlst.size()) >= k*100) {
											ful = true;
											return;
										}
									}
								}
							}
							li = j;
							pli = -1;
						}
						else if (li!=-1 && c[i][j]==(char)('1'+ord[pi1]) && (int)(rlst.size())%5<k) {
							pli = li;
							li = j;
						}
						else li = pli = -1;
					}
				}
			};
			auto csearch = [&](int i1) -> void {
				if (ful) return;
				int pi1 = min(k-1, i1+(i1%2==0?1:0));
				rep(i, n) {
					int ui = -1, pui = -1;
					rep(j, n) {
						if (c[j][i] == '0') {
							if (used[j][i] && ui!=-1) ui = pui = -1;
						}
						else if (c[j][i] == (char)('1'+ord[i1])) {
							if (ui != -1) {
								if (!glst.same(vids[ui*n+i], vids[j*n+i])) {
									rlst.emplace_back(ui, i, j, i);
									glst.merge(vids[ui*n+i], vids[j*n+i]);
									rep3(i2, ui+1, j) used[i2][i] = true;
									if ((int)(rlst.size()) >= k*100) {
										ful = true;
										return;
									}
								}
								if (pui != -1) {
									if (!glst.same(vids[pui*n+i], vids[ui*n+i])) {
										rlst.emplace_back(pui, i, ui, i);
										glst.merge(vids[pui*n+i], vids[ui*n+i]);
										rep3(i2, pui+1, ui) used[i2][i] = true;
										if ((int)(rlst.size()) >= k*100) {
											ful = true;
											return;
										}
									}
								}
							}
							ui = j;
							pui = -1;
						}
						else if (ui!=-1 && c[j][i]==(char)('1'+ord[pi1]) && (int)(rlst.size())%5<k) {
							pui = ui;
							ui = j;
						}
						else ui = pui = -1;
					}
				}
			};
			if (bi == 0) {
				rep(i1, k) rsearch(i1);
				rep(i1, k) csearch(i1);
			}
			else {
				rep(i1, k) csearch(i1);
				rep(i1, k) rsearch(i1);
			}
			auto nlst = glst.groups();
			int sco = 0;
			for (auto& vi : nlst) if ((int)(vi.size()) > 1) {
				vector<int> kcnt(k);
				for (int id : vi) kcnt[id/100]++;
				int len = vi.size();
				rep(ki, k) if (kcnt[ki] > 0) {
					sco += kcnt[ki] * (kcnt[ki]-1) / 2;
					sco -= kcnt[ki] * (len-kcnt[ki]);
				}
			}
			res = max(res, { sco, rlst, make_pair(ord, bi) });
		}
	} while (next_permutation(all(ord)));
	auto mord = get<2>(res).first;
	int mbi = get<2>(res).second, sco = get<0>(res);
	vector<tuple<int, int, int, int>> rlst = get<1>(res);
	vector<int> vtoc(k*100);
	for (auto& co : vids) vtoc[co.second] = co.first;
	random_device seed_gen;
	default_random_engine engine(seed_gen());
	uniform_int_distribution<> dcnt(1, (1<<k)), vchoose(0, 99), dchoose(0, 3), cdi(1, k);
	int mcnt = 0;
	vector<tuple<int, int, int, int>> mlst;
	const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
	do {
		auto nc = c;
		auto nvids = vids;
		auto nvtoc = vtoc;
		int di = cdi(engine);
		mcnt += di;
		vector<tuple<int, int, int, int>> amlst;
		rep(i1, di) {
			while (1) {
				int vnum = 0, vtmp = dcnt(engine);
				rep(i, k) if (vtmp >= 1<<i) vnum = i;
				int vc = vchoose(engine) + mord[vnum] * 100, dc = dchoose(engine);
				int y = nvtoc[vc] / n, x = nvtoc[vc] % n;
				int ny = y + dy[dc], nx = x + dx[dc];
				if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
				if (nvids.find(ny*n+nx) != nvids.end()) continue;
				nvids.erase(y*n+x);
				nvids[ny*n+nx] = vc;
				nvtoc[vc] = ny*n+nx;
				nc[ny][nx] = nc[y][x];
				nc[y][x] = '0';
				amlst.emplace_back(y, x, ny, nx);
				break;
			}
		}
		vector<vector<bool>> used(n, vector<bool>(n));
		vector<tuple<int, int, int, int>> nrlst;
		bool ful = false;
		dsu glst(k*100);
		auto rsearch = [&](int i1) -> void {
			if (ful) return;
			int pi1 = min(k-1, i1+(i1%2==0?1:0));
			rep(i, n) {
				int li = -1, pli = -1;
				rep(j, n) {
					if (nc[i][j] == '0') {
						if (used[i][j] && li!=-1) li = pli = -1;
					}
					else if (nc[i][j] == (char)('1'+mord[i1])) {
						if (li != -1) {
							if (!glst.same(nvids[i*n+li], nvids[i*n+j])) {
								nrlst.emplace_back(i, li, i, j);
								glst.merge(nvids[i*n+li], nvids[i*n+j]);
								rep3(i2, li+1, j) used[i][i2] = true;
								if ((int)(nrlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
							if (pli != -1) {
								if (!glst.same(nvids[i*n+pli], nvids[i*n+li])) {
									nrlst.emplace_back(i, pli, i, li);
									glst.merge(nvids[i*n+pli], nvids[i*n+li]);
									rep3(i2, pli+1, li) used[i][i2] = true;
									if ((int)(nrlst.size())+mcnt >= k*100) {
										ful = true;
										return;
									}
								}
							}
						}
						li = j;
						pli = -1;
					}
					else if (li!=-1 && nc[i][j]==(char)('1'+mord[pi1]) && ((int)(nrlst.size())+mcnt)%5<k) {
						pli = li;
						li = j;
					}
					else li = pli = -1;
				}
			}
		};
		auto csearch = [&](int i1) -> void {
			if (ful) return;
			int pi1 = min(k-1, i1+(i1%2==0?1:0));
			rep(i, n) {
				int ui = -1, pui = -1;
				rep(j, n) {
					if (nc[j][i] == '0') {
						if (used[j][i] && ui!=-1) ui = pui = -1;
					}
					else if (nc[j][i] == (char)('1'+mord[i1])) {
						if (ui != -1) {
							if (!glst.same(nvids[ui*n+i], nvids[j*n+i])) {
								nrlst.emplace_back(ui, i, j, i);
								glst.merge(nvids[ui*n+i], nvids[j*n+i]);
								rep3(i2, ui+1, j) used[i2][i] = true;
								if ((int)(nrlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
							if (pui != -1) {
								if (!glst.same(nvids[pui*n+i], nvids[ui*n+i])) {
									nrlst.emplace_back(pui, i, ui, i);
									glst.merge(nvids[pui*n+i], nvids[ui*n+i]);
									rep3(i2, pui+1, ui) used[i2][i] = true;
									if ((int)(nrlst.size())+mcnt >= k*100) {
										ful = true;
										return;
									}
								}
							}
						}
						ui = j;
						pui = -1;
					}
					else if (ui!=-1 && nc[j][i]==(char)('1'+mord[pi1]) && ((int)(nrlst.size())+mcnt)%5<k) {
						pui = ui;
						ui = j;
					}
					else ui = pui = -1;
				}
			}
		};
		if (mbi == 0) {
			rep(i1, k) rsearch(i1);
			rep(i1, k) csearch(i1);
		}
		else {
			rep(i1, k) csearch(i1);
			rep(i1, k) rsearch(i1);
		}
		auto nlst = glst.groups();
		int nsco = 0;
		for (auto& vi : nlst) if ((int)(vi.size()) > 1) {
			vector<int> kcnt(k);
			for (int id : vi) kcnt[id/100]++;
			int len = vi.size();
			rep(ki, k) if (kcnt[ki] > 0) {
				nsco += kcnt[ki] * (kcnt[ki]-1) / 2;
				nsco -= kcnt[ki] * (len-kcnt[ki]);
			}
		}
		if (nsco > sco) {
			sco = nsco;
			rlst = nrlst;
			c = nc;
			vids = nvids;
			vtoc = nvtoc;
			for (auto& mi : amlst) mlst.push_back(mi);
		}
		else {
			mcnt -= di;
		}
	} while ((clock()-start)/(double)CLOCKS_PER_SEC <= 2.8);
	int x = mlst.size();
	cout << x << endl;
	rep(i, x) cout << get<0>(mlst[i]) << ' ' << get<1>(mlst[i]) << ' ' << get<2>(mlst[i]) << ' ' << get<3>(mlst[i]) << endl;
	int y = rlst.size();
	cout << y << endl;
	rep(i, y) cout << get<0>(rlst[i]) << ' ' << get<1>(rlst[i]) << ' ' << get<2>(rlst[i]) << ' ' << get<3>(rlst[i]) << endl;
	return 0;
}
