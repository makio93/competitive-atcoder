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
int is_left(vector<vector<int>>& box, int fid, int yi, int xi) {
	repr(i, xi) if (box[yi][i] != 0) {
		if (box[yi][i] == fid) return 1;
		else return -2;
	}
	return 0;
}
int is_right(vector<vector<int>>& box, int fid, int yi, int xi) {
	rep3(i, xi+1, 10) if (box[yi][i] != 0)  {
		if (box[yi][i] == fid) return 1;
		else return -1;
	}
	return 0;
}
int is_up(vector<vector<int>>& box, int fid, int yi, int xi) {
	repr(i, yi) if (box[i][xi] != 0) {
		if (box[i][xi] == fid) return 1;
		else return -2;
	}
	return 0;
}
int is_down(vector<vector<int>>& box, int fid, int yi, int xi) {
	rep3(i, yi+1, 10) if (box[i][xi] != 0) {
		if (box[i][xi] == fid) return 1;
		else return -1;
	}
	return 0;
}

int score_calc(vector<vector<int>>& box, int sid=0, int mid=1) {
	vector<vector<bool>> visited(10, vector<bool>(10));
	int rval = 0;
	rep(i, 10) rep(j, 10) if (box[i][j]>0 && !visited[i][j] && box[i][j]!=sid) {
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
				if (ny<0 || ny>=10 || nx<0 || nx>=10 || visited[ny][nx] || box[ny][nx]==0) continue;
				if (box[ny][nx] != ci) {
					++scnt;
					continue;
				}
				que.emplace(ny, nx);
				visited[ny][nx] = true;
				++tcnt;
			}
		}
		rval += tcnt * tcnt - scnt * scnt * (mid+1);
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
	rval.first += is_left(box, fid, yi, xi) + is_right(box, fid, yi, xi);
	rval.second += is_up(box, fid, yi, xi) + is_down(box, fid, yi, xi);
	return rval;
}
int operate_test(vector<vector<int>>& box, int fid, int yi, int xi, int sid=0, int mid=1) {
	auto lbox = box, ubox = box;
	int li = 0, ui = 0;
	rep(i, xi) if (lbox[yi][i] == fid) ++li;
	rep(i, yi) if (ubox[i][xi] == fid) ++ui;
	lean(lbox, 3);
	lean(ubox, 0);
	if (score_calc(lbox, sid, mid) >= score_calc(ubox, sid, mid)) return 3;
	else return 0;
}
int dir_choose(vector<vector<int>>& box, int fid, int yi, int xi, int fi) {
	auto nbox = box;
	auto pval = horv(nbox, fid, yi, xi);
	if (fi == 0) {
		if (pval.first>0 && pval.second>0) {
			if (pval.first >= pval.second) return 3;
			else return 0;
		}
		else if (pval.first>0 || pval.second>0) {
			if (pval.first > 0) return 3;
			else return 0;
		}
		else return operate_test(nbox, fid, yi, xi, 4);
	}
	else if (fi == 1) {
		if (pval.first>0 && pval.second>0) {
			if (pval.first > pval.second) return 3;
			else return 0;
		}
		else return operate_test(nbox, fid, yi, xi, 2);
	}
	else return operate_test(nbox, fid, yi, xi, fid, 1);
}

int main() {
	int n = 100;
	vector<int> f(n);
	rep(i, n) cin >> f[i];
	vector<vector<int>> box(10, vector<int>(10));
	vector<int> fcnt(3), ford(3);
	rep(i, n) fcnt[f[i]-1]++;
	iota(all(ford), 1);
	sort(all(ford), [&](int li, int ri) -> bool { return fcnt[li-1] > fcnt[ri-1]; });
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
		int rid = dir_choose(box, f[i], yi, xi, find(all(ford),f[i])-ford.begin());
		lean(box, rid);
		cout << rc[rid] << endl;
		cout.flush();
	}
	return 0;
}
