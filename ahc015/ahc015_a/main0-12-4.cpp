// 自力での最大得点

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
const int rate = 3;

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
pair<ll, int> next_direction(vector<vector<int>>& box, mt19937_64& engine, vector<int>& f, int id, int ki, int lsz) {
	pair<ll, int> rval = { -INF, -1 };
	int slen = 100 - id - 1, len = min(slen, lsz);
	vector<int> ids(len);
	if (ki > 0) {
		if (len == slen) iota(all(ids), 0);
		else {
			vector<bool> used(slen);
			rep(i, len) {
				int sid = engine() % slen;
				while (used[sid]) sid = (sid + 1) % slen;
				used[sid] = true;
				ids[i] = sid;
			}
			sort(all(ids));
		}
	}
	rep(rid, 4) {
		auto nbox = box;
		lean(nbox, rid);
		if (id+1>=100 || ki==0) rval = max(rval, { score_calc(nbox), rid });
		else {
			ll sum = 0;
			int tid = 0, tcnt = 0;
			rep(i, 10) rep(j, 10) if (nbox[i][j] == 0) {
				if (tid<len && ids[tid]==tcnt) {
					nbox[i][j] = f[id+1];
					auto tval = next_direction(nbox, engine, f, id+1, ki-1, lsz);
					sum += tval.first;
					nbox[i][j] = 0;
					++tid;
				}
				++tcnt;
			}
			rval = max(rval, { sum, rid });
		}
	}
	return rval;
}

int main() {
	int n = 100;
	random_device seed_gen;
	mt19937_64 engine(seed_gen());
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
		int ti = (i >= 95) ? 5 : 2;
		pair<ll, int> mval = next_direction(box, engine, f, i, ti, 10);
		int rid = mval.second;
		lean(box, rid);
		cout << rc[rid] << endl;
		cout.flush();
	}
	return 0;
}
