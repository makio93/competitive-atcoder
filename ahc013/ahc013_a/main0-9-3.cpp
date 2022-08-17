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

int n, k;

bool check2(int r1, int c1, int r2, int c2, unordered_map<int, int>& vids, dsu& glst, vector<vector<int>>& kcnt) {
	int val1 = 0, val2 = 0;
	int gid1 = glst.leader(vids[r1*n+c1]), gid2 = glst.leader(vids[r2*n+c2]);
	rep(i, k) if (kcnt[gid1][i] > 0) {
		val1 += kcnt[gid1][i] * (kcnt[gid1][i]-1) / 2;
		val1 -= kcnt[gid1][i] * (glst.size(gid1) - kcnt[gid1][i]);
	}
	rep(i, k) if (kcnt[gid2][i] > 0) {
		val1 += kcnt[gid2][i] * (kcnt[gid2][i]-1) / 2;
		val1 -= kcnt[gid2][i] * (glst.size(gid2) - kcnt[gid2][i]);
	}
	vector<int> scnt(k);
	rep(i, k) scnt[i] += kcnt[gid1][i];
	rep(i, k) scnt[i] += kcnt[gid2][i];
	int ssum = 0;
	rep(i, k) ssum += scnt[i];
	rep(i, k) if (scnt[i] > 0) {
		val2 += scnt[i] * (scnt[i]-1) / 2;
		val2 -= scnt[i] * (ssum - scnt[i]);
	}
	return val2 > val1;
}

bool check3(int r1, int c1, int r2, int c2, int r3, int c3, 
	unordered_map<int, int>& vids, dsu& glst, vector<vector<int>>& kcnt) {
	int val1 = 0, val2 = 0;
	int gid1 = glst.leader(vids[r1*n+c1]), gid2 = glst.leader(vids[r2*n+c2]), gid3 = glst.leader(vids[r3*n+c3]);
	rep(i, k) if (kcnt[gid1][i] > 0) {
		val1 += kcnt[gid1][i] * (kcnt[gid1][i]-1) / 2;
		val1 -= kcnt[gid1][i] * (glst.size(gid1) - kcnt[gid1][i]);
	}
	rep(i, k) if (kcnt[gid2][i] > 0) {
		val1 += kcnt[gid2][i] * (kcnt[gid2][i]-1) / 2;
		val1 -= kcnt[gid2][i] * (glst.size(gid2) - kcnt[gid2][i]);
	}
	rep(i, k) if (kcnt[gid3][i] > 0) {
		val1 += kcnt[gid3][i] * (kcnt[gid3][i]-1) / 2;
		val1 -= kcnt[gid3][i] * (glst.size(gid3) - kcnt[gid3][i]);
	}
	vector<int> scnt(k);
	rep(i, k) scnt[i] += kcnt[gid1][i];
	rep(i, k) scnt[i] += kcnt[gid2][i];
	rep(i, k) scnt[i] += kcnt[gid3][i];
	int ssum = 0;
	rep(i, k) ssum += scnt[i];
	rep(i, k) if (scnt[i] > 0) {
		val2 += scnt[i] * (scnt[i]-1) / 2;
		val2 -= scnt[i] * (ssum - scnt[i]);
	}
	return val2 > val1;
}

void rsearch(int k1, vector<string>& c, unordered_map<int, int>& vids, vector<vector<bool>>& used, dsu& glst, 
	vector<vector<int>>& kcnt, vector<tuple<int, int, int, int>>& rlst, bool& ful, int mcnt=0) {
	if (ful) return;
	rep(i, n) {
		int li = -1, pli = -1;
		rep(j, n) {
			if (c[i][j] == '0') { if (used[i][j] && li!=-1) li = pli = -1; }
			else if (c[i][j] == (char)('1'+k1)) {
				if (li != -1) {
					if (!glst.same(vids[i*n+li], vids[i*n+j])) {
						if (pli != -1) {
							if (check3(i, pli, i, li, i, j, vids, glst, kcnt) && 
								((!glst.same(vids[i*n+pli],vids[i*n+li])&&(int)(rlst.size())+mcnt+2<=k*100)||
								(glst.same(vids[i*n+pli],vids[i*n+li])&&(int)(rlst.size())+mcnt+1<=k*100))) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+pli])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+li])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+j])][ii];
								glst.merge(vids[i*n+li], vids[i*n+j]);
								rlst.emplace_back(i, li, i, j);
								if (!glst.same(vids[i*n+pli], vids[i*n+li])) {
									glst.merge(vids[i*n+pli], vids[i*n+li]);
									rlst.emplace_back(i, pli, i, li);
								}
								rep(ii, k) kcnt[glst.leader(vids[i*n+j])][ii] = nkcnt[ii];
								rep3(ii, pli+1, li) used[i][ii] = true;
								rep3(ii, li+1, j) used[i][ii] = true;
								if ((int)(rlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
						}
						else {
							if (check2(i, li, i, j, vids, glst, kcnt) && (int)(rlst.size())+mcnt+1<=k*100) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+li])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+j])][ii];
								glst.merge(vids[i*n+li], vids[i*n+j]);
								rlst.emplace_back(i, li, i, j);
								rep(ii, k) kcnt[glst.leader(vids[i*n+j])][ii] = nkcnt[ii];
								rep3(ii, li+1, j) used[i][ii] = true;
								if ((int)(rlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
						}
					}
					else if (pli!=-1 && !glst.same(vids[i*n+pli], vids[i*n+li])) {
						if (check2(i, pli, i, li, vids, glst, kcnt) && (int)(rlst.size())+mcnt+1<=k*100) {
							vector<int> nkcnt(k);
							rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+pli])][ii];
							rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+li])][ii];
							glst.merge(vids[i*n+pli], vids[i*n+li]);
							rlst.emplace_back(i, pli, i, li);
							rep(ii, k) kcnt[glst.leader(vids[i*n+li])][ii] = nkcnt[ii];
							rep3(ii, pli+1, li) used[i][ii] = true;
							if ((int)(rlst.size())+mcnt >= k*100) {
								ful = true;
								return;
							}
						}
					}
				}
				li = j;
				pli = -1;
			}
			else if (li!=-1 && c[i][j]!=(char)('1'+k1) && c[i][li]==(char)('1'+k1)) {
				pli = li;
				li = j;
			}
			else li = pli = -1;
		}
	}
}

void csearch(int k1, vector<string>& c, unordered_map<int, int>& vids, vector<vector<bool>>& used, dsu& glst, 
	vector<vector<int>>& kcnt, vector<tuple<int, int, int, int>>& rlst, bool& ful, int mcnt=0) {
	if (ful) return;
	rep(i, n) {
		int ui = -1, pui = -1;
		rep(j, n) {
			if (c[j][i] == '0') { if (used[j][i] && ui!=-1) ui = pui = -1; }
			else if (c[j][i] == (char)('1'+k1)) {
				if (ui != -1) {
					if (!glst.same(vids[ui*n+i], vids[j*n+i])) {
						if (pui != -1) {
							if (check3(pui, i, ui, i, j, i, vids, glst, kcnt) && 
								((!glst.same(vids[pui*n+i],vids[ui*n+i])&&(int)(rlst.size())+mcnt+2<=k*100)||
								(glst.same(vids[pui*n+i],vids[ui*n+i])&&(int)(rlst.size())+mcnt+1<=k*100))) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[pui*n+i])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[ui*n+i])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[j*n+i])][ii];
								glst.merge(vids[ui*n+i], vids[j*n+i]);
								rlst.emplace_back(ui, i, j, i);
								if (!glst.same(vids[pui*n+i], vids[ui*n+i])) {
									glst.merge(vids[pui*n+i], vids[ui*n+i]);
									rlst.emplace_back(pui, i, ui, i);
								}
								rep(ii, k) kcnt[glst.leader(vids[j*n+i])][ii] = nkcnt[ii];
								rep3(ii, pui+1, ui) used[ii][i] = true;
								rep3(ii, ui+1, j) used[ii][i] = true;
								if ((int)(rlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
						}
						else {
							if (check2(ui, i, j, i, vids, glst, kcnt) && (int)(rlst.size())+mcnt+1<=k*100) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[ui*n+i])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[j*n+i])][ii];
								glst.merge(vids[ui*n+i], vids[j*n+i]);
								rlst.emplace_back(ui, i, j, i);
								rep(ii, k) kcnt[glst.leader(vids[j*n+i])][ii] = nkcnt[ii];
								rep3(ii, ui+1, j) used[ii][i] = true;
								if ((int)(rlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
						}
					}
					else if (pui!=-1 && !glst.same(vids[pui*n+i], vids[ui*n+i])) {
						if (check2(pui, i, ui, i, vids, glst, kcnt) && (int)(rlst.size())+mcnt+1<=k*100) {
							vector<int> nkcnt(k);
							rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[pui*n+i])][ii];
							rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[ui*n+i])][ii];
							glst.merge(vids[pui*n+i], vids[ui*n+i]);
							rlst.emplace_back(pui, i, ui, i);
							rep(ii, k) kcnt[glst.leader(vids[ui*n+i])][ii] = nkcnt[ii];
							rep3(ii, pui+1, ui) used[ii][i] = true;
							if ((int)(rlst.size())+mcnt >= k*100) {
								ful = true;
								return;
							}
						}
					}
				}
				ui = j;
				pui = -1;
			}
			else if (ui!=-1 && c[j][i]!=(char)('1'+k1) && c[ui][i]==(char)('1'+k1)) {
				pui = ui;
				ui = j;
			}
			else ui = pui = -1;
		}
	}
}

int main() {
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
		rep(bi, 1<<k) {
			vector<vector<bool>> used(n, vector<bool>(n));
			vector<tuple<int, int, int, int>> rlst;
			bool ful = false;
			dsu glst(k*100);
			vector<vector<int>> kcnt(k*100, vector<int>(k));
			rep(ii, k) rep(jj, 100) kcnt[ii*100+jj][ii] = 1;
			rep(i1, k) {
				if ((bi>>i1)&1) rsearch(ord[i1], c, vids, used, glst, kcnt, rlst, ful);
				else csearch(ord[i1], c, vids, used, glst, kcnt, rlst, ful);
			}
			rep(i1, k) {
				if ((bi>>i1)&1) csearch(ord[i1], c, vids, used, glst, kcnt, rlst, ful);
				else rsearch(ord[i1], c, vids, used, glst, kcnt, rlst, ful);
			}
			auto nlst = glst.groups();
			int sco = 0;
			for (auto& vi : nlst) if ((int)(vi.size()) > 1) {
				int gid = glst.leader(vi.front()), ssum = glst.size(gid);
				rep(ki, k) if (kcnt[gid][ki] > 0) {
					sco += kcnt[gid][ki] * (kcnt[gid][ki]-1) / 2;
					sco -= kcnt[gid][ki] * (ssum-kcnt[gid][ki]);
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
		vector<vector<int>> kcnt(k*100, vector<int>(k));
		rep(ii, k) rep(jj, 100) kcnt[ii*100+jj][ii] = 1;
		rep(i1, k) {
			if ((mbi>>i1)&1) rsearch(mord[i1], nc, nvids, used, glst, kcnt, nrlst, ful, mcnt);
			else csearch(mord[i1], nc, nvids, used, glst, kcnt, nrlst, ful, mcnt);
		}
		rep(i1, k) {
			if ((mbi>>i1)&1) csearch(mord[i1], nc, nvids, used, glst, kcnt, nrlst, ful, mcnt);
			else rsearch(mord[i1], nc, nvids, used, glst, kcnt, nrlst, ful, mcnt);
		}
		auto nlst = glst.groups();
		int nsco = 0;
		for (auto& vi : nlst) if ((int)(vi.size()) > 1) {
			int gid = glst.leader(vi.front()), ssum = glst.size(gid);
			rep(ki, k) if (kcnt[gid][ki] > 0) {
				nsco += kcnt[gid][ki] * (kcnt[gid][ki]-1) / 2;
				nsco -= kcnt[gid][ki] * (ssum-kcnt[gid][ki]);
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
		else mcnt -= di;
	} while ((clock()-start)/(double)CLOCKS_PER_SEC <= 2.8);
	int x = mlst.size();
	cout << x << endl;
	rep(i, x) cout << get<0>(mlst[i]) << ' ' << get<1>(mlst[i]) << ' ' << get<2>(mlst[i]) << ' ' << get<3>(mlst[i]) << endl;
	int y = rlst.size();
	cout << y << endl;
	rep(i, y) cout << get<0>(rlst[i]) << ' ' << get<1>(rlst[i]) << ' ' << get<2>(rlst[i]) << ' ' << get<3>(rlst[i]) << endl;
	return 0;
}
