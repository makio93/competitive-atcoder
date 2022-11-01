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

const ll INF = (ll)(1e18);

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
	rep(i, (4-rid)%4) roll(box);
}
pair<ll, int> next_direction(vector<vector<int>>& box, vector<int>& f, int id, int ki=0) {
	pair<ll, int> rval = { -INF, -1 };
	rep(rid, 4) {
		auto nbox = box;
		lean(nbox, rid);
		if (id+1>=100 || ki==0) rval = max(rval, { score_calc(nbox), rid });
		else {
			ll sum = 0;
			rep(i, 10) rep(j, 10) if (nbox[i][j] == 0) {
				nbox[i][j] = f[id+1];
				auto tval = next_direction(nbox, f, id+1, ki-1);
				sum += tval.first;
				nbox[i][j] = 0;
			}
			int tid = 100 - id - 1;
			rval = max(rval, { sum, rid });
		}
	}
	return rval;
}

int main() {
	clock_t start = clock();
	int n = 100;
	vector<int> f(n);
	rep(i, n) cin >> f[i];
	vector<vector<int>> box(10, vector<int>(10));
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
		int ti = ((i>=50&&i%10==0) || i>=80) ? 2 : 1;
		pair<ll, int> mval = next_direction(box, f, i, ti);
		int rid = mval.second;
		lean(box, rid);
		cout << rc[rid] << endl;
		cout.flush();
	}
	return 0;
}
