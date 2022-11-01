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

const vector<char> rc = { 'F', 'R', 'B', 'L' };
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
void roll(vector<vector<int>>& box) {
	vector<vector<int>> tmp = box;
	rep(i, 10) rep(j, 10) box[i][j] = tmp[j][9-i];
}
bool is_left(vector<vector<int>>& box, int fid, int yi, int xi) {
	repr(i, xi) if (box[yi][i] != 0) {
		if (box[yi][i] == fid) return true;
		else return false;
	}
	return true;
}
bool is_right(vector<vector<int>>& box, int fid, int yi, int xi) {
	rep3(i, xi+1, 10) if (box[yi][i] != 0)  {
		if (box[yi][i] == fid) return true;
		else return false;
	}
	return true;
}
bool is_up(vector<vector<int>>& box, int fid, int yi, int xi) {
	repr(i, yi) if (box[i][xi] != 0) {
		if (box[i][xi] == fid) return true;
		else return false;
	}
	return true;
}
bool is_down(vector<vector<int>>& box, int fid, int yi, int xi) {
	rep3(i, yi+1, 10) if (box[i][xi] != 0) {
		if (box[i][xi] == fid) return true;
		else return false;
	}
	return true;
}

int score_calc(vector<vector<int>>& box) {
	vector<vector<bool>> visited(10, vector<bool>(10));
	int rval = 0;
	rep(i, 10) rep(j, 10) if (box[i][j]>0 && !visited[i][j]) {
		queue<pair<int, int>> que;
		int tcnt = 0, ci = box[i][j], scnt = 0;
		que.emplace(i, j);
		visited[i][j] = true;
		++tcnt;
		while (!que.empty()) {
			auto pi = que.front(); que.pop();
			int yi = pi.first, xi = pi.second;
			rep(ii, 4) {
				int ny = yi + dy[ii], nx = xi + dx[ii];
				if (ny<0 || ny>=10 || nx<0 || nx>=10 || visited[ny][nx]) continue;
				if (box[ny][nx] != ci) {
					++scnt;
					continue;
				}
				que.emplace(ny, nx);
				visited[ny][nx] = true;
				++tcnt;
			}
		}
		rval += tcnt * tcnt - scnt * scnt * 4;
	}
	return rval;
}
void lean(vector<vector<int>>& box, int rid) {
	rep(i, rid) roll(box);
	rep(i, 10) {
		int tid = 0;
		rep(j, 10) if (box[j][i] > 0) {
			box[tid][i] = box[j][i];
			++tid;
		}
		while (tid < 10) {
			box[tid][i] = 0;
			++tid;
		}
	}
	rep(i, 4-rid) roll(box);
}
pair<int, int> horv(vector<vector<int>>& box, int fid, int yi, int xi) {
	pair<int, int> rval = { 0, 0 };
	rval.first += (is_left(box, fid, yi, xi) ? 1 : -1) + (is_right(box, fid, yi, xi) ? 1 : -1);
	rval.second += (is_up(box, fid, yi, xi) ? 1 : -1) + (is_down(box, fid, yi, xi) ? 1 : -1);
	return rval;
}
int dir_choose(vector<vector<int>>& box, int fid, int yi, int xi) {
	auto nbox = box;
	auto pval = horv(nbox, fid, yi, xi);
	if (pval.first>0 && pval.second>=0) return 3;
	else if (pval.second>0 && pval.first>=0) return 0;
	else {
		auto lbox = nbox, ubox = nbox;
		int li = 0, ui = 0;
		rep(i, xi) if (lbox[yi][i] == fid) ++li;
		rep(i, yi) if (ubox[i][xi] == fid) ++ui;
		lean(lbox, 3);
		lean(ubox, 0);
		if (score_calc(lbox) >= score_calc(ubox)) return 3;
		else return 0;
	}
}

int main() {
	int n = 100;
	vector<int> f(n);
	rep(i, n) cin >> f[i];
	vector<vector<int>> box(10, vector<int>(10));
	random_device seed_gen;
	mt19937_64 engine(seed_gen());
	rep(i, n) {
		int pi;
		cin >> pi;
		int yi = -1, xi = -1;
		rep(j, n) if (box[j/10][j%10] == 0) {
			--pi;
			if (pi == 0) {
				box[j/10][j%10] = f[i];
				yi = j / 10;
				xi = j % 10;
				break;
			}
		}
		int rid = dir_choose(box, f[i], yi, xi);
		lean(box, rid);
		cout << rc[rid] << endl;
		cout.flush();
	}
	return 0;
}
