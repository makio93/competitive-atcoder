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
vector<int> score_calc(vector<vector<int>>& box, vector<int>& ford) {
	vector<vector<bool>> visited(10, vector<bool>(10));
	vector<int> rval(3);
	rep(i, 10) rep(j, 10) if (box[i][j]>0 && !visited[i][j]) {
		queue<pair<int, int>> que;
		int tcnt = 0, ci = box[i][j];
		que.emplace(i, j);
		visited[i][j] = true;
		++tcnt;
		while (!que.empty()) {
			auto pi = que.front(); que.pop();
			int yi = pi.first, xi = pi.second;
			rep(ii, 4) {
				int ny = yi + dy[ii], nx = xi + dx[ii];
				if (ny<0 || ny>=10 || nx<0 || nx>=10 || visited[ny][nx] || box[ny][nx]!=ci) continue;
				que.emplace(ny, nx);
				visited[ny][nx] = true;
				++tcnt;
			}
		}
		int fi = find(all(ford), ci) - ford.begin();
		rval[fi] += tcnt * tcnt;
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
}
vector<int> score_test(vector<vector<int>>& box, int rid, vector<int>& f, int pid, vector<int>& ford) {
	auto nbox = box;
	lean(nbox, rid);
	rep(i, 4-rid) roll(nbox);
	return score_calc(nbox, ford);
}

int main() {
	int n = 100;
	vector<int> f(n);
	rep(i, n) cin >> f[i];
	vector<int> fcnt(3), ford(3);
	rep(i, n) fcnt[f[i]-1]++;
	iota(all(ford), 1);
	sort(all(ford), [&](int li, int ri) -> bool { return fcnt[li-1] > fcnt[ri-1]; });
	vector<vector<int>> box(10, vector<int>(10));
	random_device seed_gen;
	mt19937_64 engine(seed_gen());
	rep(i, n) {
		int pi;
		cin >> pi;
		rep(j, n) if (box[j/10][j%10] == 0) {
			--pi;
			if (pi == 0) {
				box[j/10][j%10] = f[i];
				break;
			}
		}
		pair<vector<int>, int> mval = { vector<int>({ -1, -1, -1 }), -1 };
		rep(j, 2) mval = max(mval, { score_test(box, j, f, i+1, ford), j });
		int rid = mval.second;
		lean(box, rid);
		cout << rc[rid] << endl;
		cout.flush();
	}
	return 0;
}
