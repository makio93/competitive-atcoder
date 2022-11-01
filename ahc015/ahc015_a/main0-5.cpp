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
	repr(i, xi) if (box[yi][i] == fid) return true;
	return false;
}
bool is_up(vector<vector<int>>& box, int fid, int yi, int xi) {
	repr(i, yi) if (box[i][xi] == fid) return true;
	return false;
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
}
int dir_choose(vector<vector<int>>& box, int fid, int yi, int xi) {
	auto nbox = box;
	if (is_left(nbox, fid, yi, xi)) return 3;
	else if (is_up(nbox, fid, yi, xi)) return 0;
	else {
		auto tbox = nbox;
		int li = 0;
		rep(i, xi) if (tbox[yi][i] == fid) ++li;
		lean(tbox, 3);
		rep(i, 1) roll(tbox);
		if (is_left(tbox, fid, yi, li) || is_up(tbox, fid, yi, li)) return 3;
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
