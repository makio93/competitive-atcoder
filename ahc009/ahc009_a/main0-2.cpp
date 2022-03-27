// 本番2,スコアが悪い,未提出

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

int main() {
	int si, sj, ti, tj;
	double p;
	cin >> si >> sj >> ti >> tj >> p;
	vector<vector<bool>> wall(20*20, vector<bool>(20*20));
	rep(i, 20) {
		string hi;
		cin >> hi;
		rep(j, 19) wall[i*20+j][i*20+j+1] = wall[i*20+j+1][i*20+j] = (hi[j] == '1');
	}
	rep(i, 19) {
		string vi;
		cin >> vi;
		rep(j, 20) wall[i*20+j][(i+1)*20+j] = wall[(i+1)*20+j][i*20+j] = (vi[j] == '1');
	}
	vector<vector<vector<vector<double>>>> dist(20, vector<vector<vector<double>>>(20, vector<vector<double>>(5, vector<double>(201))));
	queue<tuple<int, int, int, int, double>> que;
	que.emplace(si, sj, 4, 0, 1.0);
	dist[si][sj][4][0] = 1.0;
	auto next_dir = [&](int nowi, int nowj, int tari, int tarj) -> int {
		if (nowi==tari && nowj==tarj) return -1;
		const int INF = (int)(1e9);
		pair<int, int> mval = { INF, -1 };
		rep(i1, 4) {
			vector<vector<int>> tdist(20, vector<int>(20, INF));
			tdist[nowi][nowj] = 0;
			queue<pair<int, int>> tque;
			const vector<int> tdi = { -1, 0, 1, 0 }, tdj = { 0, 1, 0, -1 };
			int tsi = nowi + tdi[i1], tsj = nowj + tdj[i1];
			if (tsi<0 || tsi>=20 || tsj<0 || tsj>=20 || wall[nowi*20+nowj][tsi*20+tsj]) continue; 
			tdist[tsi][tsj] = 1;
			tque.emplace(tsi, tsj);
			while (!tque.empty()) {
				auto tpi = tque.front(); tque.pop();
				int tvi = tpi.first, tvj = tpi.second, tdisti = tdist[tvi][tvj];
				rep(i2, 4) {
					int tni = tvi + tdi[i2], tnj = tvj + tdj[i2];
					if (tni<0 || tni>=20 || tnj<0 || tnj>=20 || wall[tvi*20+tvj][tni*20+tnj]) continue;
					if (tdist[tni][tnj] <= tdisti+1) continue;
					tdist[tni][tnj] = tdisti + 1;
					tque.emplace(tni, tnj);
				}
			}
			mval = min(mval, { tdist[tari][tarj], i1 });
		}
		return mval.second;
	};
	while (!que.empty()) {
		auto tpi = que.front(); que.pop();
		int vi = get<0>(tpi), vj = get<1>(tpi), ri = get<2>(tpi), disti = get<3>(tpi);
		double pi = get<4>(tpi);
		if (pi < dist[vi][vj][ri][disti]) continue;
		if (disti+1 > 200) continue;
		const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
		int ndr = next_dir(vi, vj, ti, tj);
		if (ndr != -1) {
			int ni = vi + di[ndr], nj = vj + dj[ndr];
			if (ni<0 || ni>=20 || nj<0 || nj>=20 || wall[vi*20+vj][ni*20+nj]) continue;
			dist[ni][nj][ndr][disti+1] += pi * p;
			que.emplace(ni, nj, ndr, disti+1, dist[ni][nj][ndr][disti+1]);
			dist[vi][vj][4][disti+1] += pi * (1.0 - p);
			que.emplace(vi, vj, 4, disti+1, dist[vi][vj][4][disti+1]);
			cout << disti << endl;
		}
	}
	tuple<double, int, int> mval = { 0.0, 0, 0 };
	rep(i, 201) rep(j, 5) mval = max(mval, { dist[ti][tj][j][i], j, i });
	const string dir = "URDL";
	const vector<int> rdi = { 1, 0, -1, 0 }, rdj = { 0, -1, 0, 1 };
	pair<double, string> mres = { 0.0, "" };
	int stai = get<2>(mval), posi = ti, posj = tj;
	string nres;
	rep3r(i, 1, stai+1) {
		pair<double, int> mval1 = { 0.0, 0 }, mval2 = { 0.0, 0 };
		rep(j, 5) mval1 = max(mval1, { dist[posi][posj][j][i], j });
		rep(j, 4) mval2 = max(mval2, { dist[posi][posj][j][i], j });
		nres.push_back(dir[mval2.second]);
		if (mval1.second != 4) posi += rdi[mval1.second], posj += rdj[mval1.second];
		if (posi==si && posj==sj) mres = max(mres, { mval1.first, nres });
	}
	string res = mres.second;
	reverse(all(res));
	cout << res << endl;
	return 0;
}
