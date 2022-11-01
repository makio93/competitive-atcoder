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
int score_calc(vector<vector<int>>& box) {
	vector<vector<bool>> visited(10, vector<bool>(10));
	int rval = 0;
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
		rval += tcnt * tcnt;
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
vector<int> generate_ord(mt19937_64& engine, int len) {
	vector<int> ord(len, -1);
	rep(i, len) {
		int tid = engine() % (len-i) + 1;
		rep(j, len) if (ord[j] == -1) {
			--tid;
			if (tid == 0) {
				ord[j] = i;
				break;
			}
		}
	}
	return ord;
}
ll score_test(vector<vector<int>>& box, mt19937_64& engine, int rid, vector<int>& f, int pid, int rcnt=100) {
	auto nbox = box;
	lean(nbox, rid);
	rep(i, 4-rid) roll(nbox);
	ll rval = 0;
	rep(i0, rcnt) {
		auto ord = generate_ord(engine, 100-pid);
		int tid = 0;
		auto tbox = nbox;
		rep(i, 10) rep(j, 10) if (tbox[i][j] == 0) {
			tbox[i][j] = f[ord[tid]+pid];
			++tid;
		}
		rval += score_calc(tbox);
	}
	return rval;
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
		rep(j, n) if (box[j/10][j%10] == 0) {
			--pi;
			if (pi == 0) {
				box[j/10][j%10] = f[i];
				break;
			}
		}
		pair<ll, int> mval = { -1, -1 };
		rep(j, 4) mval = max(mval, { score_test(box, engine, j, f, i+1), j });
		int rid = mval.second;
		lean(box, rid);
		cout << rc[rid] << endl;
		cout.flush();
	}
	return 0;
}
