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
		rval += tcnt * tcnt - scnt * mid * mid / 2;
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
int operate_test_all(vector<vector<int>>& box, int fid, int yi, int xi, int sid=0, int mid=1) {
	auto rbox = box, dbox = box, lbox = box, ubox = box;
	int ri = 0, di = 0, li = 0, ui = 0;
	rep3(i, xi+1, 10) if (rbox[yi][i] == fid) ++ri;
	rep3(i, yi+1, 10) if (dbox[i][xi] == fid) ++di;
	rep(i, xi) if (lbox[yi][i] == fid) ++li;
	rep(i, yi) if (ubox[i][xi] == fid) ++ui;
	lean(rbox, 1);
	lean(dbox, 2);
	lean(lbox, 3);
	lean(ubox, 0);
	vector<int> slst = { score_calc(ubox, sid, mid), score_calc(rbox, sid, mid), score_calc(dbox, sid, mid), score_calc(lbox, sid, mid) };
	return max_element(all(slst)) - slst.begin();
}
int dir_choose(vector<vector<int>>& box, int fid, int yi, int xi, int fi) {
	auto nbox = box;
	return operate_test_all(nbox, fid, yi, xi, 1<<(2-fi));
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
