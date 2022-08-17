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

bool check2(int r1, int c1, int r2, int c2, map<int, int>& vids, dsu& glst, vector<vector<int>>& kcnt) {
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
	map<int, int>& vids, dsu& glst, vector<vector<int>>& kcnt) {
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
	return val2 > (int)(val1 * (8.5 + (clock()-start)/(double)CLOCKS_PER_SEC) / 10 + 0.5);
}

bool pmove(int ri, int ci, bool hor, vector<string>& c, map<int, int>& vids, 
	vector<vector<int>>& used, vector<pair<int, int>>& rlst, vector<tuple<int, int, int, int>>& tmlst, int mcnt) {
	if ((int)(rlst.size()+tmlst.size())+mcnt+2 > k*100) return false;
	if (hor) {
		if (ri-1>=0 && c[ri-1][ci]=='0' && !(used[ri][ci]&1) && !(used[ri-1][ci]&1)) {
			int pid = vids[ri*n+ci];
			vids.erase(ri*n+ci);
			vids[(ri-1)*n+ci] = pid;
			c[ri-1][ci] = c[ri][ci];
			c[ri][ci] = '0';
			tmlst.emplace_back(ri, ci, ri-1, ci);
			return true;
		}
		else if (ri+1<n && c[ri+1][ci]=='0' && !(used[ri][ci]&1) && !(used[ri+1][ci]&1)) {
			int pid = vids[ri*n+ci];
			vids.erase(ri*n+ci);
			vids[(ri+1)*n+ci] = pid;
			c[ri+1][ci] = c[ri][ci];
			c[ri][ci] = '0';
			tmlst.emplace_back(ri, ci, ri+1, ci);
			return true;
		}
		else return false;
	}
	else {
		if (ci-1>=0 && c[ri][ci-1]=='0' && !((used[ri][ci]>>1)&1) && !((used[ri][ci-1]>>1)&1)) {
			int pid = vids[ri*n+ci];
			vids.erase(ri*n+ci);
			vids[ri*n+ci-1] = pid;
			c[ri][ci-1] = c[ri][ci];
			c[ri][ci] = '0';
			tmlst.emplace_back(ri, ci, ri, ci-1);
			return true;
		}
		else if (ci+1<n && c[ri][ci+1]=='0' && !((used[ri][ci]>>1)&1) && !((used[ri][ci+1]>>1)&1)) {
			int pid = vids[ri*n+ci];
			vids.erase(ri*n+ci);
			vids[ri*n+ci+1] = pid;
			c[ri][ci+1] = c[ri][ci];
			c[ri][ci] = '0';
			tmlst.emplace_back(ri, ci, ri, ci+1);
			return true;
		}
		else return false;
	}
}

void rsearch(int k1, vector<string>& c, map<int, int>& vids, vector<vector<int>>& used, dsu& glst, vector<vector<int>>& kcnt, 
	vector<pair<int, int>>& rlst, bool& ful, vector<tuple<int, int, int, int>>& tmlst, int mcnt=0) {
	if (ful) return;
	rep(i, n) {
		int li = -1, pli = -1;
		rep(j, n) {
			if (c[i][j] == '0') { if (used[i][j] && li!=-1) li = pli = -1; }
			else if (c[i][j] == (char)('1'+k1)) {
				if (li != -1) {
					if (!glst.same(vids[i*n+li], vids[i*n+j])) {
						if (pli != -1) {
							if ((int)(glst.size(vids[i*n+li]))==1 && pmove(i, li, true, c, vids, used, rlst, tmlst, mcnt)) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+pli])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+j])][ii];
								glst.merge(vids[i*n+pli], vids[i*n+j]);
								rlst.emplace_back(vids[i*n+pli], vids[i*n+j]);
								rep(ii, k) kcnt[glst.leader(vids[i*n+j])][ii] = nkcnt[ii];
								rep3(ii, pli+1, j) used[i][ii] |= 1;
								li = pli;
								if ((int)(rlst.size()+tmlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
							else if (check3(i, pli, i, li, i, j, vids, glst, kcnt) && 
								((!glst.same(vids[i*n+pli],vids[i*n+li])&&(int)(rlst.size()+tmlst.size())+mcnt+2<=k*100)||
								(glst.same(vids[i*n+pli],vids[i*n+li])&&(int)(rlst.size()+tmlst.size())+mcnt+1<=k*100))) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+pli])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+li])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+j])][ii];
								glst.merge(vids[i*n+li], vids[i*n+j]);
								rlst.emplace_back(vids[i*n+li], vids[i*n+j]);
								if (!glst.same(vids[i*n+pli], vids[i*n+li])) {
									glst.merge(vids[i*n+pli], vids[i*n+li]);
									rlst.emplace_back(vids[i*n+pli], vids[i*n+li]);
								}
								rep(ii, k) kcnt[glst.leader(vids[i*n+j])][ii] = nkcnt[ii];
								rep3(ii, pli+1, li) used[i][ii] |= 1;
								rep3(ii, li+1, j) used[i][ii] |= 1;
								if ((int)(rlst.size()+tmlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
						}
						else {
							if (check2(i, li, i, j, vids, glst, kcnt) && (int)(rlst.size()+tmlst.size())+mcnt+1<=k*100) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+li])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+j])][ii];
								glst.merge(vids[i*n+li], vids[i*n+j]);
								rlst.emplace_back(vids[i*n+li], vids[i*n+j]);
								rep(ii, k) kcnt[glst.leader(vids[i*n+j])][ii] = nkcnt[ii];
								rep3(ii, li+1, j) used[i][ii] |= 1;
								if ((int)(rlst.size()+tmlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
						}
					}
					else if (pli!=-1 && !glst.same(vids[i*n+pli], vids[i*n+li])) {
						if (check2(i, pli, i, li, vids, glst, kcnt) && (int)(rlst.size()+tmlst.size())+mcnt+1<=k*100) {
							vector<int> nkcnt(k);
							rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+pli])][ii];
							rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[i*n+li])][ii];
							glst.merge(vids[i*n+pli], vids[i*n+li]);
							rlst.emplace_back(vids[i*n+pli], vids[i*n+li]);
							rep(ii, k) kcnt[glst.leader(vids[i*n+li])][ii] = nkcnt[ii];
							rep3(ii, pli+1, li) used[i][ii] |= 1;
							if ((int)(rlst.size()+tmlst.size())+mcnt >= k*100) {
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

void csearch(int k1, vector<string>& c, map<int, int>& vids, vector<vector<int>>& used, dsu& glst, vector<vector<int>>& kcnt, 
	vector<pair<int, int>>& rlst, bool& ful, vector<tuple<int, int, int, int>>& tmlst, int mcnt=0) {
	if (ful) return;
	rep(i, n) {
		int ui = -1, pui = -1;
		rep(j, n) {
			if (c[j][i] == '0') { if (used[j][i] && ui!=-1) ui = pui = -1; }
			else if (c[j][i] == (char)('1'+k1)) {
				if (ui != -1) {
					if (!glst.same(vids[ui*n+i], vids[j*n+i])) {
						if (pui != -1) {
							if ((int)(glst.size(vids[ui*n+i]))==1 && pmove(ui, i, false, c, vids, used, rlst, tmlst, mcnt)) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[pui*n+i])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[j*n+i])][ii];
								glst.merge(vids[pui*n+i], vids[j*n+i]);
								rlst.emplace_back(vids[pui*n+i], vids[j*n+i]);
								rep(ii, k) kcnt[glst.leader(vids[j*n+i])][ii] = nkcnt[ii];
								rep3(ii, pui+1, j) used[ii][i] |= 2;
								ui = pui;
								if ((int)(rlst.size()+tmlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
							else if (check3(pui, i, ui, i, j, i, vids, glst, kcnt) && 
								((!glst.same(vids[pui*n+i],vids[ui*n+i])&&(int)(rlst.size()+tmlst.size())+mcnt+2<=k*100)||
								(glst.same(vids[pui*n+i],vids[ui*n+i])&&(int)(rlst.size()+tmlst.size())+mcnt+1<=k*100))) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[pui*n+i])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[ui*n+i])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[j*n+i])][ii];
								glst.merge(vids[ui*n+i], vids[j*n+i]);
								rlst.emplace_back(vids[ui*n+i], vids[j*n+i]);
								if (!glst.same(vids[pui*n+i], vids[ui*n+i])) {
									glst.merge(vids[pui*n+i], vids[ui*n+i]);
									rlst.emplace_back(vids[pui*n+i], vids[ui*n+i]);
								}
								rep(ii, k) kcnt[glst.leader(vids[j*n+i])][ii] = nkcnt[ii];
								rep3(ii, pui+1, ui) used[ii][i] |= 2;
								rep3(ii, ui+1, j) used[ii][i] |= 2;
								if ((int)(rlst.size()+tmlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
						}
						else {
							if (check2(ui, i, j, i, vids, glst, kcnt) && (int)(rlst.size()+tmlst.size())+mcnt+1<=k*100) {
								vector<int> nkcnt(k);
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[ui*n+i])][ii];
								rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[j*n+i])][ii];
								glst.merge(vids[ui*n+i], vids[j*n+i]);
								rlst.emplace_back(vids[ui*n+i], vids[j*n+i]);
								rep(ii, k) kcnt[glst.leader(vids[j*n+i])][ii] = nkcnt[ii];
								rep3(ii, ui+1, j) used[ii][i] |= 2;
								if ((int)(rlst.size()+tmlst.size())+mcnt >= k*100) {
									ful = true;
									return;
								}
							}
						}
					}
					else if (pui!=-1 && !glst.same(vids[pui*n+i], vids[ui*n+i])) {
						if (check2(pui, i, ui, i, vids, glst, kcnt) && (int)(rlst.size()+tmlst.size())+mcnt+1<=k*100) {
							vector<int> nkcnt(k);
							rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[pui*n+i])][ii];
							rep(ii, k) nkcnt[ii] += kcnt[glst.leader(vids[ui*n+i])][ii];
							glst.merge(vids[pui*n+i], vids[ui*n+i]);
							rlst.emplace_back(vids[pui*n+i], vids[ui*n+i]);
							rep(ii, k) kcnt[glst.leader(vids[ui*n+i])][ii] = nkcnt[ii];
							rep3(ii, pui+1, ui) used[ii][i] |= 2;
							if ((int)(rlst.size()+tmlst.size())+mcnt >= k*100) {
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
	map<int, int> vids;
	rep(i1, k) {
		int cnt = 0;
		rep(i, n) rep(j, n) if (c[i][j] == (char)('1'+i1)) {
			vids[i*n+j] = i1 * 100 + cnt;
			++cnt;
		}
	}
	vector<int> ord(k);
	iota(all(ord), 0);
	tuple<int, tuple<vector<pair<int, int>>, vector<tuple<int, int, int, int>>, 
		vector<string>, map<int, int>>, pair<vector<int>, int>> res =
		{ -INF, { vector<pair<int, int>>(), vector<tuple<int, int, int, int>>(), c, vids }, { vector<int>(), -1 } };
	do {
		rep(bi, 2) {
			vector<vector<int>> used(n, vector<int>(n));
			vector<pair<int, int>> rlst;
			vector<tuple<int, int, int, int>> mlst;
			bool ful = false;
			dsu glst(k*100);
			vector<vector<int>> kcnt(k*100, vector<int>(k));
			rep(ii, k) rep(jj, 100) kcnt[ii*100+jj][ii] = 1;
			auto nc = c;
			auto nvids = vids;
			if (bi == 0) {
				rep(i1, k) rsearch(ord[i1], nc, nvids, used, glst, kcnt, rlst, ful, mlst);
				rep(i1, k) csearch(ord[i1], nc, nvids, used, glst, kcnt, rlst, ful, mlst);
			}
			else {
				rep(i1, k) csearch(ord[i1], nc, nvids, used, glst, kcnt, rlst, ful, mlst);
				rep(i1, k) rsearch(ord[i1], nc, nvids, used, glst, kcnt, rlst, ful, mlst);
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
			res = max(res, { sco, make_tuple(rlst, mlst, nc, nvids), make_pair(ord, bi) });
		}
	} while (next_permutation(all(ord)));
	auto mord = get<2>(res).first;
	int mbi = get<2>(res).second, sco = get<0>(res);
	vector<pair<int, int>> rlst = get<0>(get<1>(res));
	vector<tuple<int, int, int, int>> mlst = get<1>(get<1>(res));
	c = get<2>(get<1>(res));
	vids = get<3>(get<1>(res));
	random_device seed_gen;
	default_random_engine engine(seed_gen());
	uniform_int_distribution<> dcnt(1, (1<<k)), vchoose(0, 99), dchoose(0, 3), cdi(1, k);
	const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
	vector<int> vtoc;
	do {
		vtoc.assign(k*100, 0);
		for (auto& co : vids) vtoc[co.second] = co.first;
		auto nc = c;
		auto nvids = vids;
		auto nvtoc = vtoc;
		int di = min(k*100-(int)(rlst.size()+mlst.size()), cdi(engine));
		auto amlst = mlst;
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
		vector<vector<int>> used(n, vector<int>(n));
		vector<pair<int, int>> nrlst;
		bool ful = false;
		dsu glst(k*100);
		vector<vector<int>> kcnt(k*100, vector<int>(k));
		rep(ii, k) rep(jj, 100) kcnt[ii*100+jj][ii] = 1;
		if (mbi == 0) {
			rep(i1, k) rsearch(mord[i1], nc, nvids, used, glst, kcnt, nrlst, ful, amlst);
			rep(i1, k) csearch(mord[i1], nc, nvids, used, glst, kcnt, nrlst, ful, amlst);
		}
		else {
			rep(i1, k) csearch(mord[i1], nc, nvids, used, glst, kcnt, nrlst, ful, amlst);
			rep(i1, k) rsearch(mord[i1], nc, nvids, used, glst, kcnt, nrlst, ful, amlst);
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
			mlst = amlst;
		}
	} while ((clock()-start)/(double)CLOCKS_PER_SEC <= 2.8);
	int x = mlst.size();
	cout << x << endl;
	rep(i, x) cout << get<0>(mlst[i]) << ' ' << get<1>(mlst[i]) << ' ' << get<2>(mlst[i]) << ' ' << get<3>(mlst[i]) << endl;
	int y = rlst.size();
	cout << y << endl;
	vtoc.assign(k*100, 0);
	for (auto& co : vids) vtoc[co.second] = co.first;
	rep(i, y) cout << (vtoc[get<0>(rlst[i])]/n) << ' ' << (vtoc[get<0>(rlst[i])]%n) << ' ' << (vtoc[get<1>(rlst[i])]/n) << ' ' << (vtoc[get<1>(rlst[i])]%n) << endl;
	return 0;
}
