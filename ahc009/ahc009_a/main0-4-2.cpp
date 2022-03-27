// 本番4-2,本番提出2

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
	vector<vector<vector<int>>> dist(20, vector<vector<int>>(20, vector<int>(4, (int)(1e9))));
	queue<tuple<int, int, int>> que;
	dist[si][sj][0] = 0;
	que.emplace(si, sj, 0);
	while (!que.empty()) {
		auto tpi = que.front(); que.pop();
		int vi = get<0>(tpi), vj = get<1>(tpi), vdir = get<2>(tpi), vdi = dist[vi][vj][vdir];
		if (vdi+1 > 200) continue;
		const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
		rep(i2, 4) {
			int ni = vi + di[i2], nj = vj + dj[i2];
			if (ni<0 || ni>=20 || nj<0 || nj>=20 || wall[vi*20+vj][ni*20+nj]) continue;
			if (dist[ni][nj][i2] <= vdi+1) continue;
			dist[ni][nj][i2] = vdi + 1;
			que.emplace(ni, nj, i2);
		}
	}
	srand(time(NULL));
	const string ctar = "DLUR";
	string res;
	int posi = ti, posj = tj;
	const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
	while (posi!=si || posj!=sj) {
		pair<int, int> ndir = { (int)(1e9), -1 };
		rep(i1, 4) {
			int ni = posi + di[i1], nj = posj + dj[i1];
			if (ni<0 || ni>=20 || nj<0 || nj>=20 || wall[posi*20+posj][ni*20+nj]) continue;
			rep(i2, 4) ndir = min(ndir, { dist[ni][nj][i2], i1 });
		}
		res.push_back(ctar[ndir.second]);
		if (rand()/(double)RAND_MAX >= p) res.push_back(ctar[ndir.second]);
		posi += di[ndir.second], posj += dj[ndir.second];
	}
	reverse(all(res));
	cout << res << endl;
	return 0;
}
