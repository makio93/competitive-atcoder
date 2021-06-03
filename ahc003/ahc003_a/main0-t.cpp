#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中に作成1、書いただけ、ローカルテスト用

const int INF = (int)(1e9);

vector<vector<int>> orih, oriv;

vector<vector<vector<int>>> dist;
pair<int, int> ps, pt;

void change(int pres) {
	int mdist = abs(pt.first-ps.first) + abs(pt.second-ps.second), ndist = (int)round((pres+0.5)/mdist);
	pair<int, int> sec = { ps.second, pt.second };
	if (sec.first > sec.second) swap(sec.first, sec.second);
	/*
	rep3(i, ps.first, pt.first+1) rep3(j, sec.first, sec.second+1) {
		if (i < pt.first) dist[i][j][0] = (dist[i][j][0] + ndist) / 2;
		if (j < sec.second) dist[i][j][1] = (dist[i][j][1] + ndist) / 2;
	}
	*/
}

using pqd = pair<pair<int, char>, pair<int, int>>;

string query(pair<int, int> s, pair<int, int> t) {
	bool rev = false, left = false;
	if (s.first > t.first) {
		swap(s, t);
		rev = true;
	}
	if (s.second > t.second) left = true;
	int hlen = abs(t.first-s.first), wlen = abs(t.second-s.second);
	vector<vector<pair<int, char>>> disti(hlen+1, vector<pair<int, char>>(wlen+1, { INF, 'N' }));
	priority_queue<pqd, vector<pqd>, greater<pqd>> que;
	int sj2 = (left ? wlen : 0);
	que.emplace(make_pair(0, 'S'), make_pair(0, sj2));
	disti[0][sj2] = { 0, 'S' };
	while (!que.empty()) {
		auto p = que.top(); que.pop();
		int d = p.first.first, y = p.second.first, x = p.second.second; char c = p.first.second;
		if (disti[y][x] != make_pair(d, c)) continue;
		int valy = y + s.first, valx = x + min(s.second, t.second);
		vector<int> dy = { 1, 0 }, dx = { 0, (left ? -1 : 1) };
		vector<char> dc = { 'D', ((left) ? 'L' : 'R') };
		rep(i1, 2) {
			int ny = y + dy[i1], nx = x + dx[i1];
			if (ny<0 || ny>hlen || nx<0 || nx>wlen) continue;
			int valx2 = (i1==1&&left) ? (valx-1) : valx;
			int nd = d + dist[valy][valx2][i1];
			if (nd >= disti[ny][nx].first) continue;
			que.emplace(make_pair(nd, dc[i1]), make_pair(ny, nx));
			disti[ny][nx] = { nd, dc[i1] };
		}
	}
	pair<int, int> v = { hlen, (left ? 0 : wlen) };
	string res;
	res += disti[v.first][v.second].second;
	vector<int> dy = { 1, 0, -1, 0 }, dx = { 0, -1, 0, 1 };
	vector<char> dc = { 'U', 'R', 'D', 'L' };
	while (res.back() != 'S') {
		rep(i1, 4) if (dc[i1] == res.back()) {
			v.first += dy[i1]; v.second += dx[i1];
		}
		res += disti[v.first][v.second].second;
	}
	res.pop_back();
	if (rev) {
		for (char& c : res) {
			rep(i1, 4) if (c == dc[i1]) {
				c = dc[(i1+2)%4];
				break;
			}
		}
	}
	else reverse(all(res));
	return res;
}

int calc(pair<int, int> s, pair<int, int> t, string rstr) {
	pair<int, int> v = s;
	int res = 0;
	vector<char> dc = { 'U', 'R', 'D', 'L' };
	vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
	for (char& c : rstr) {
		rep(i1, 4) if (c == dc[i1]) {
			if (i1==1 || i1==2) {
				int id = (i1==1) ? 1 : 0;
				if (id==0) res += oriv[v.first][v.second];
				if (id==1) res += orih[v.first][v.second];
			}
			v.first += dy[i1]; v.second += dx[i1];
			if (i1==0 || i1==3) {
				int id = (i1==0) ? 0 : 1;
				if (id==0) res += oriv[v.first][v.second];
				if (id==1) res += orih[v.first][v.second];
			}
			break;
		}
	}
	return res;
}

int main() {
	orih = vector<vector<int>>(30, vector<int>(29));
	oriv = vector<vector<int>>(29, vector<int>(30));
	rep(i, 30) rep(j, 29) cin >> orih[i][j];
	rep(i, 29) rep(j, 30) cin >> oriv[i][j];
	dist = vector<vector<vector<int>>>(30, vector<vector<int>>(30, vector<int>(2, 5000)));
	int pres = 0;
	rep(k, 1000) {
		int si, sj, ti, tj, ai;
		double ei;
		cin >> si >> sj >> ti >> tj >> ai >> ei;
		if (k-1 >= 0) change(pres);
		string res = query({si, sj}, {ti, tj});
		cout << res << endl;
		cout.flush();
		pres = calc({si,sj}, {ti,tj}, res);
		//cin >> pres;
		ps = { si, sj }, pt = { ti, tj };
	}
	return 0;
}
