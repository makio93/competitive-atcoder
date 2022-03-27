// 本番5,未完成

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
	const string ctar = "URDL";
	vector<vector<string>> dist(20, vector<string>(20));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
	dist[si][sj] = "";
	que.emplace(0, si, sj);
	while (!que.empty()) {
		auto tpi = que.top(); que.pop();
		int plen = get<0>(tpi), vi = get<1>(tpi), vj = get<2>(tpi);
		if ((int)(dist[vi][vj].length()) != plen) continue;
		if (plen+1 > 200) continue;
		string vpath = dist[vi][vj];
		const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
		rep(i1, 4) {
			int nlen = 0, ni = vi, nj = vj;
			while ((ni+di[i1])>=0 && (ni+di[i1])<20 && (nj+dj[i1])>=0 && (nj+dj[i1])<20 && !wall[ni*20+nj][(ni+di[i1])*20+(nj+dj[i1])]) {
				ni += di[i1]; nj += dj[i1]; ++nlen;
			}
			if (nlen == 0) continue;
			int tlen = (int)(nlen), nplen = plen + tlen;
			if (nplen > 200) continue;
			if (!dist[ni][nj].empty() && (int)(dist[ni][nj].length())<=nplen) continue;
			dist[ni][nj] = vpath + string(tlen, ctar[i1]);
			que.emplace(nplen, ni, nj);
		}
	}
	cout << dist[ti][tj] << endl;
	return 0;
}
