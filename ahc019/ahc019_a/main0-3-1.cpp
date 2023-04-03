// 本番3-1,不具合あり

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

using vbi = vector<bool>;
using vbii = vector<vector<bool>>;
using vbiii = vector<vector<vector<bool>>>;
using vbiipi = vector<vector<vector<pair<bool, bool>>>>;
using vs = vector<string>;

const int INF = (int)(1e9);
const double DINF = 1e18;

random_device seed_gen;

struct Silhouette {
	int d;
	vbii f, r;
	Silhouette(vs& sf, vs& sr) {
		d = sf.size();
		input(sf, f), input(sr, r);
	}
	void input(vs& s, vbii& b) {
		b.assign(d, vbi(d));
		rep(i, d) rep(j, d) b[i][j] = s[i][j] == '1';
	}
};

struct TimeUnionFind {
	int n, step, pa, pb;
	dsu *ds;
	unordered_map<int, int> toleader;
	TimeUnionFind *prev;
	TimeUnionFind(int n_, TimeUnionFind *prev_=NULL) {
		n = n_;
		ds = new dsu(n);
		if (ds == NULL) {
			cout << "Out!" << endl;
			exit(0);
		}
		step = 0, this->prev = prev_, pa = -1, pb = -1;
	}
	TimeUnionFind(TimeUnionFind *pds, int a, int b) {
		if (pds == NULL) {
			cout << "Out!" << endl;
			exit(0);
		}
		n = pds->n;
		prev = pds;
		ds = new dsu(n);
		if (ds == NULL) {
			cout << "Out!" << endl;
			exit(0);
		}
		auto glst = prev->ds->groups();
		for (const auto& vi : glst) {
			int vlen = vi.size();
			rep(i, vlen-1) ds->merge(vi[i], vi[i+1]);
			toleader[ds->leader(vi[0])] = prev->leader(vi[0]);
		}
		step = prev->step + 1;
		pa = a, pb = b;
	}
	~TimeUnionFind() { if (ds != NULL) delete ds; }
	int merge(int a, int b) { return leader(ds->merge(a, b)); }
	int leader(int a) { return toleader.find(ds->leader(a)) != toleader.end() ? toleader[ds->leader(a)] : (toleader[ds->leader(a)] = ds->leader(a)); }
};

struct TUFManager {
	TimeUnionFind *now;
	set<pair<int, TimeUnionFind*>> db;
	TUFManager(int n) {
		now = new TimeUnionFind(n);
		if (now == NULL) {
			cout << "Out!" << endl;
			exit(0);
		}
		db.emplace(now->step, now);
	}
	int merge(int a, int b) {
		if (now->ds->same(a, b)) return now->merge(a, b);
		now = new TimeUnionFind(now, a, b);
		if (now == NULL) {
			cout << "Out!" << endl;
			exit(0);
		}
		db.emplace(now->step, now);
		return now->merge(a, b);
	}
	bool same(int a, int b) { return now->ds->same(a, b); }
	int leader(int a) { return now->leader(a); }
	int size(int a) { return now->ds->size(a); }
	bool undo() {
		if (now->prev == NULL) return false;
		auto tmp = now;
		now = now->prev;
		db.erase({tmp->step, tmp});
		if (tmp != NULL) delete tmp;
		return true;
	}
};

struct Cube {
	int d;
	Silhouette *sl;
	vbiii c;
	vbiipi xw, yw, zw;
	TUFManager *blocks;
	unordered_set<string> slst;
	unordered_map<int, unordered_set<string>::iterator> blst;
	unordered_set<int> target_walls;
	Cube(Silhouette& sl_) {
		sl = &sl_;
		d = sl->d;
		c = vector(d, vector(d, vector(d, false)));
		xw = vector(d, vector(d, vector(d, make_pair(false, false))));
		yw = vector(d, vector(d, vector(d, make_pair(false, false))));
		zw = vector(d, vector(d, vector(d, make_pair(false, false))));
		init();
		blocks = NULL;
	}
	void init() {
		init_cube();
		init_wall();
	}
	void adapt_cube(Cube& tc) {
		if (this->count_block() == tc.count_block()) return;
		if (this->count_block() < tc.count_block()) {
			tc.adapt_cube(*this);
			return;
		}
		rem_block(this->count_block()-tc.count_block());
		init_wall();
	}
	int cell_id(int xi, int yi, int zi) {
		return xi*d*d + yi*d + zi;
	}
	int wall_id(int xi, int yi, int zi, int dir, bool right=true) {
		if (right) {
			if (dir == 0) ++xi;
			if (dir == 1) ++yi;
			if (dir == 2) ++zi;
		}
		return cell_id(xi, yi, zi) * 3 + dir;
	}
	tuple<int, int, int> cell2idx(int cid) {
		int xi = cid / d / d, yi = cid / d % d, zi = cid % d;
		return make_tuple(xi, yi, zi);
	}
	pair<int, int> wall2cells(int wid) {
		int dir = wid % 3, rid = wid / 3, lid = rid;
		if (dir == 0) lid -= d * d;
		if (dir == 1) lid -= d;
		if (dir == 2) lid--;
		return make_pair(lid, rid);
	}
	void roll1(vector<vector<vector<bool>>>& cells, int& d1, int& d2, int& d3) {
		vector ncells(d2+1, vector(d1+1, vector(d3+1, false)));
		rep(i2, d2+1) rep(i1, d1+1) rep(i3, d3+1) ncells[i2][i1][i3] = cells[d1-i1][i2][i3];
		cells.swap(ncells);
		swap(d1, d2);
	}
	void roll2(vector<vector<vector<bool>>>& cells, int& d1, int& d2, int& d3) {
		vector ncells(d3+1, vector(d2+1, vector(d1+1, false)));
		rep(i3, d3+1) rep(i2, d2+1) rep(i1, d1+1) ncells[i3][i2][i1] = cells[d1-i1][i2][i3];
		cells.swap(ncells);
		swap(d1, d3);
	}
	string calc_str(vector<vector<vector<bool>>>& cells, int& d1, int& d2, int& d3) {
		string res;
		res.push_back((char)('a'+d1)), res.push_back((char)('a'+d2)), res.push_back((char)('a'+d3));
		rep(i1, d1+1) rep(i2, d2+1) rep(i3, d3+1) res.push_back(cells[i1][i2][i3]?'1':'0');
		return res;
	}
	string block_str(set<tuple<int, int, int>>& pst) {
		int lx = INF, ly = INF, lz = INF, d1 = -INF, d2 = -INF, d3 = -INF;
		for (const auto& ti : pst) {
			lx = min(lx, get<0>(ti)), d1 = max(d1, get<0>(ti));
			ly = min(ly, get<1>(ti)), d2 = max(d2, get<1>(ti));
			lz = min(lz, get<2>(ti)), d3 = max(d3, get<2>(ti));
		}
		d1 -= lx, d2 -= ly, d3 -= lz;
		vector cells(d1+1, vector(d2+1, vector(d3+1, false)));
		for (const auto& ti : pst) cells[get<0>(ti)-lx][get<1>(ti)-ly][get<2>(ti)-lz] = true;
		string bstr = string(3+(d1+1)*(d2+1)*(d3+1), 'z');
		rep(i, 4) {
			rep(j, 4) {
				bstr = min(bstr, calc_str(cells, d1, d2, d3));
				roll1(cells, d1, d2, d3);
			}
			roll2(cells, d1, d2, d3);
		}
		roll1(cells, d1, d2, d3), roll2(cells, d1, d2, d3);
		rep(i, 2) {
			rep(j, 4) {
				bstr = min(bstr, calc_str(cells, d1, d2, d3));
				roll1(cells, d1, d2, d3);
			}
			rep(j, 2) roll2(cells, d1, d2, d3);
		}
		return bstr;
	}
	void init_data() {
		blocks = new TUFManager(d*d*d);
		if (blocks == NULL) {
			cout << "Out!" << endl;
			exit(0);
		}
		vector visited(d, vector(d, vector(d, false)));
		const vector<int> dx = { -1, 1, 0, 0, 0, 0 }, dy = { 0, 0, -1, 1, 0, 0 }, dz = { 0, 0, 0, 0, -1, 1 };
		auto dfs = [&](auto dfs, set<tuple<int, int, int>>& pst, int xi, int yi, int zi) -> void {
			visited[xi][yi][zi] = true;
			pst.emplace(xi, yi, zi);
			rep(i, 6) {
				int nx = xi + dx[i], ny = yi + dy[i], nz = zi + dz[i];
				if (nx<0 || nx>=d || ny<0 || ny>=d || nz<0 || nz>=d || !c[nx][ny][nz] || is_wall(xi,yi,zi,nx,ny,nz)!=0 || visited[nx][ny][nz]) continue;
				blocks->merge(cell_id(xi, yi, zi), cell_id(nx, ny, nz));
				dfs(dfs, pst, nx, ny, nz);
			}
		};
		set<tuple<int, int, int>> pst;
		rep(i, d) rep(j, d) rep(k, d) if (c[i][j][k] && !visited[i][j][k]) {
			dfs(dfs, pst, i, j, k);
			auto str = block_str(pst);
			if (slst.find(str) == slst.end()) slst.insert(str);
			blst[blocks->leader(cell_id(i, j, k))] = slst.find(str);
			pst.clear();
		}
		norm_wall();
		rep(i, d) rep(j, d) rep(k, d) if (c[i][j][k]) {
			if (i+1<d && c[i+1][j][k] && xw[i][j][k].second) target_walls.insert(wall_id(i,j,k,0));
			if (j+1<d && c[i][j+1][k] && yw[i][j][k].second) target_walls.insert(wall_id(i,j,k,1));
			if (k+1<d && c[i][j][k+1] && zw[i][j][k].second) target_walls.insert(wall_id(i,j,k,2));
		}
	}
	void init_cube() {
		rep(i, d) rep(j, d) rep(k, d) if (sl->f[k][i] && sl->r[k][j]) c[i][j][k] = true;
	}
	void init_wall() {
		xw.assign(d, vector(d, vector(d, make_pair(false, false))));
		yw.assign(d, vector(d, vector(d, make_pair(false, false))));
		zw.assign(d, vector(d, vector(d, make_pair(false, false))));
		rep(i, d) rep(j, d) rep(k, d) if (c[i][j][k]) {
			xw[i][j][k] = { true, true };
			yw[i][j][k] = { true, true };
			zw[i][j][k] = { true, true };
		}
	}
	void norm_wall() {
		if (blocks == NULL) return;
		rep(i, d) rep(j, d) rep(k, d) if (c[i][j][k]) {
			if (i+1<d && c[i+1][j][k] && blocks->same(cell_id(i,j,k),cell_id(i+1,j,k)) && xw[i][j][k].second) {
				xw[i][j][k].second = xw[i+1][j][k].first = false;
			}
			if (j+1<d && c[i][j+1][k] && blocks->same(cell_id(i,j,k),cell_id(i,j+1,k)) && yw[i][j][k].second) {
				yw[i][j][k].second = yw[i][j+1][k].first = false;
			}
			if (k+1<d && c[i][j][k+1] && blocks->same(cell_id(i,j,k),cell_id(i,j,k+1)) && zw[i][j][k].second) {
				zw[i][j][k].second = zw[i][j][k+1].first = false;
			}
		}
	}
	int is_wall(int x1, int y1, int z1, int x2, int y2, int z2) {
		int dcnt = 0, dlen = 0;
		if (x2-x1 != 0) ++dcnt, dlen = abs(x2-x1);
		if (y2-y1 != 0) ++dcnt, dlen = abs(y2-y1);
		if (z2-z1 != 0) ++dcnt, dlen = abs(z2-z1);
		if (dcnt!=1 || dlen!=1) return -1;
		if (x2-x1 != 0) {
			if (x1 > x2) swap(x1, x2);
			return xw[x1][y1][z1].second ? 1 : 0;
		}
		if (y2-y1 != 0) {
			if (y1 > y2) swap(y1, y2);
			return yw[x1][y1][z1].second ? 1 : 0;
		}
		if (z2-z1 != 0) {
			if (z1 > z2) swap(z1, z2);
			return zw[x1][y1][z1].second ? 1 : 0;
		}
		return -1;
	}
	int search_wall(string& s1, string& s2, string& s3) {
		for (const int& wid : target_walls) {
			auto [li, ri] = wall2cells(wid);
			li = blocks->leader(li), ri = blocks->leader(ri);
			if ((*blst[li]==s1&&*blst[ri]==s2) || (*blst[li]==s2&&*blst[ri]==s1)) {
				auto str = mix_str(wid);
				if (str == s3) return wid;
			}
		}
		return -1;
	}
	bool rem_check(int xi, int yi, int zi) {
		int cnt1 = 0, cnt2 = 0;
		if (sl->f[zi][xi]) { rep(i, d) if (c[xi][i][zi]) ++cnt1; }
		else cnt1 = 2;
		if (sl->r[zi][yi]) { rep(i, d) if (c[i][yi][zi]) ++cnt2; }
		else cnt2 = 2;
		return (cnt1>=2 && cnt2>=2);
	}
	void rem_block(int dc) {
		rep(i, d) rep(j, d) rep(k, d) if (c[i][j][k] && rem_check(i, j, k)) {
			c[i][j][k] = false;
			--dc;
			if (dc == 0) return;
		}
	}
	string mix_str(int wid) {
		auto [li, ri] = wall2cells(wid);
		auto [xi, yi, zi] = cell2idx(li);
		vector visited(d, vector(d, vector(d, false)));
		const vector<int> dx = { -1, 1, 0, 0, 0, 0 }, dy = { 0, 0, -1, 1, 0, 0 }, dz = { 0, 0, 0, 0, -1, 1 };
		set<tuple<int, int, int>> pst;
		auto dfs = [&](auto dfs, int xi, int yi, int zi) -> void {
			visited[xi][yi][zi] = true;
			pst.emplace(xi, yi, zi);
			rep(i, 6) {
				int nx = xi + dx[i], ny = yi + dy[i], nz = zi + dz[i];
				if (nx<0 || nx>=d || ny<0 || ny>=d || nz<0 || nz>=d || !c[nx][ny][nz] || is_wall(xi,yi,zi,nx,ny,nz)!=0 || visited[nx][ny][nz]) continue;
				dfs(dfs, nx, ny, nz);
			}
		};
		dfs(dfs, xi, yi, zi);
		auto [rxi, ryi, rzi] = cell2idx(ri);
		dfs(dfs, rxi, ryi, rzi);
		return block_str(pst);
	}
	void remove_wall(int wid) {
		auto [li, ri] = wall2cells(wid);
		auto [xi, yi, zi] = cell2idx(li);
		int dir = wid % 3;
		if (dir == 0) xw[xi][yi][zi].second = xw[xi+1][yi][zi].first = false;
		if (dir == 1) yw[xi][yi][zi].second = yw[xi][yi+1][zi].first = false;
		if (dir == 2) zw[xi][yi][zi].second = zw[xi][yi][zi+1].first = false;
		blst.erase(blocks->leader(li)), blst.erase(blocks->leader(ri));
		target_walls.erase(wid);
		blocks->merge(li, ri);
		vector visited(d, vector(d, vector(d, false)));
		const vector<int> dx = { -1, 1, 0, 0, 0, 0 }, dy = { 0, 0, -1, 1, 0, 0 }, dz = { 0, 0, 0, 0, -1, 1 };
		set<tuple<int, int, int>> pst;
		auto dfs = [&](auto dfs, int xi, int yi, int zi) -> void {
			visited[xi][yi][zi] = true;
			pst.emplace(xi, yi, zi);
			rep(i, 6) {
				int nx = xi + dx[i], ny = yi + dy[i], nz = zi + dz[i];
				if (nx<0 || nx>=d || ny<0 || ny>=d || nz<0 || nz>=d || !c[nx][ny][nz] || is_wall(xi,yi,zi,nx,ny,nz)!=0 || visited[nx][ny][nz]) continue;
				dfs(dfs, nx, ny, nz);
			}
		};
		dfs(dfs, xi, yi, zi);
		auto str = block_str(pst);
		if (slst.find(str) == slst.end()) slst.insert(str);
		blst[blocks->leader(li)] = slst.find(str);
	}
	void repair_wall(int wid) {
		auto [li, ri] = wall2cells(wid);
		auto [xi, yi, zi] = cell2idx(li);
		int dir = wid % 3;
		if (dir == 0) xw[xi][yi][zi].second = xw[xi+1][yi][zi].first = true;
		if (dir == 1) yw[xi][yi][zi].second = yw[xi][yi+1][zi].first = true;
		if (dir == 2) zw[xi][yi][zi].second = zw[xi][yi][zi+1].first = true;
		blst.erase(blocks->leader(li));
		target_walls.insert(wid);
		blocks->undo();
		vector visited(d, vector(d, vector(d, false)));
		const vector<int> dx = { -1, 1, 0, 0, 0, 0 }, dy = { 0, 0, -1, 1, 0, 0 }, dz = { 0, 0, 0, 0, -1, 1 };
		auto dfs = [&](auto dfs, set<tuple<int, int, int>>& pst, int xi, int yi, int zi) -> void {
			visited[xi][yi][zi] = true;
			pst.emplace(xi, yi, zi);
			rep(i, 6) {
				int nx = xi + dx[i], ny = yi + dy[i], nz = zi + dz[i];
				if (nx<0 || nx>=d || ny<0 || ny>=d || nz<0 || nz>=d || !c[nx][ny][nz] || is_wall(xi,yi,zi,nx,ny,nz)!=0 || visited[nx][ny][nz]) continue;
				dfs(dfs, pst, nx, ny, nz);
			}
		};
		set<tuple<int, int, int>> lst, rst;
		dfs(dfs, lst, xi, yi, zi);
		auto [rxi, ryi, rzi] = cell2idx(ri);
		dfs(dfs, rst, rxi, ryi, rzi);
		auto lstr = block_str(lst), rstr = block_str(rst);
		if (slst.find(lstr) == slst.end()) slst.insert(lstr);
		if (slst.find(rstr) == slst.end()) slst.insert(rstr);
		blst[blocks->leader(li)] = slst.find(lstr);
		blst[blocks->leader(ri)] = slst.find(rstr);
	}
	int count_block() {
		int res = 0;
		rep(i, d) rep(j, d) rep(k, d) if (c[i][j][k]) ++res;
		return res;
	}
	pair<int, vector<int>> make_cube() {
		map<string, unordered_set<int>> olst;
		for (const auto& pi : blst) olst[*pi.second].insert(pi.first);
		int oid = 1;
		unordered_map<int, int> oids;
		for (const auto& pi : olst) for (const int& id : pi.second) {
			oids[id] = oid;
			++oid;
		}
		vector<int> cb(d*d*d);
		rep(xi, d) rep(yi, d) rep(zi, d) if (c[xi][yi][zi]) cb[cell_id(xi,yi,zi)] = oids[blocks->leader(cell_id(xi,yi,zi))];
		return { oid-1, cb };
	}
};

class Puzzle {
	int d;
	Cube *c1, *c2;
	mt19937_64 *engine;
public:
	Puzzle(Silhouette& sl1_, Silhouette& sl2_) {
		engine = new mt19937_64(seed_gen());
		c1 = new Cube(sl1_);
		c2 = new Cube(sl2_);
		d = c1->d;
		c1->adapt_cube(*c2);
		c1->init_data(), c2->init_data();
	}
	double calc_diff(string& s1, string& s2, string& s3) {
		if (count(all(s1),'1')==0 || count(all(s2),'1')==0 || count(all(s3),'1')==0) return -DINF;
		return (1.0/count(all(s1),'1')+1.0/count(all(s2),'1')) - (1.0/count(all(s3),'1'));
	}
	pair<int, int> choose_walls() {
		pair<double, pair<int, int>> mval = { -DINF, { INF, -1 } };
		vector<int> walls_list(all(c1->target_walls));
		while (mval.second.first==INF && !walls_list.empty()) {
			int ti = (*engine)() % (int)(walls_list.size());
			auto [li, ri] = c1->wall2cells(walls_list[ti]);
			string s1 = *c1->blst[c1->blocks->leader(li)], s2 = *c1->blst[c1->blocks->leader(ri)], s3 = c1->mix_str(walls_list[ti]);
			int rval = c2->search_wall(s1, s2, s3);
			if (rval != -1) mval = max(mval, { calc_diff(s1, s2, s3), make_pair(walls_list[ti], rval) });
			walls_list.erase(walls_list.begin()+ti);
		}
		return mval.second;
	}
	double eval_cubes() {
		double sval = 0.0;
		int scnt = 0;
		vector<int> walls_list(all(c1->target_walls));
		int wlen = walls_list.size();
		for (int i=0; i*i<=wlen&&!walls_list.empty(); ++i) {
			int ti = (*engine)() % (int)(walls_list.size());
			auto [li, ri] = c1->wall2cells(walls_list[ti]);
			string s1 = *c1->blst[c1->blocks->leader(li)], s2 = *c1->blst[c1->blocks->leader(ri)], s3 = c1->mix_str(walls_list[ti]);
			int rval = c2->search_wall(s1, s2, s3);
			if (rval != -1) sval += calc_diff(s1, s2, s3);
			++scnt;
			walls_list.erase(walls_list.begin()+ti);
		}
		if (scnt > 0) sval /= scnt;
		return sval;
	}
	void remove_walls(pair<int, int> wids) {
		c1->remove_wall(wids.first);
		c2->remove_wall(wids.second);
	}
	void repair_walls(pair<int, int> wids) {
		c1->repair_wall(wids.first);
		c2->repair_wall(wids.second);
	}
	pair<double, pair<int, int>> search_choice() {
		pair<double, pair<int, int>> mval = { -DINF, { -1, -1 } };
		vector<int> walls_list(all(c1->target_walls));
		for (const int& ti : walls_list) {
			auto [li, ri] = c1->wall2cells(ti);
			string s1 = *c1->blst[c1->blocks->leader(li)], s2 = *c1->blst[c1->blocks->leader(ri)], s3 = c1->mix_str(ti);
			int rval = c2->search_wall(s1, s2, s3);
			if (rval == -1) continue;
			double pre = calc_diff(s1, s2, s3);
			auto nwids = make_pair(ti, rval);
			remove_walls(nwids);
			mval = max(mval, { pre+eval_cubes(), nwids });
			repair_walls(nwids);
		}
		return mval;
	}
	bool proceed() {
		auto pi = search_choice();
		if (pi.second.first == -1) return false;
		remove_walls(pi.second);
		return true;
	}
	tuple<int, vector<int>, vector<int>> output_data() {
		auto p1 = c1->make_cube();
		return { p1.first, p1.second, c2->make_cube().second };
	}
};

Puzzle input() {
	int d;
	cin >> d;
	vector<string> sf1(d), sr1(d), sf2(d), sr2(d);
	rep(i, d) cin >> sf1[i];
	rep(i, d) cin >> sr1[i];
	rep(i, d) cin >> sf2[i];
	rep(i, d) cin >> sr2[i];
	Silhouette sl1(sf1, sr1), sl2(sf2, sr2);
	return Puzzle(sl1, sl2);
}

void output(Puzzle& pzl) {
	auto [n, b1, b2] = pzl.output_data();
	cout << n << endl;
	int blen = b1.size();
	rep(i, blen) cout << b1[i] << (i<blen-1?' ':'\n');
	rep(i, blen) cout << b2[i] << (i<blen-1?' ':'\n');
}

clock_t start = clock();

int main() {
	auto pzl = input();
	while ((double)(clock()-start)/CLOCKS_PER_SEC <= 5.0) if (!pzl.proceed()) break;
	output(pzl);
	return 0;
}
