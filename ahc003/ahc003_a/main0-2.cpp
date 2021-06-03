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

// 本番中に作成2、未完成、提出用

const int INF = (int)(1e9);

const double TLI = (double)(1.9) / 500500;
const double t0 = 2e3, t1 = 6e2;

int tcnt;
clock_t start_c;

//vector<vector<int>> orih, oriv;

vector<vector<vector<int>>> dist;
deque<set<int>> street;
vector<vector<int>> path;
vector<int> bans;
vector<pair<int, int>> spos, tpos;

ll pcalc();
ll pdist(int);

/*
void change(pair<int, int> ps, pair<int, int> pt) {
	int pdist = abs(pt.first-ps.first) + abs(pt.second-ps.second), cdist = (pdist * 3 + plen + 2) / 4;
	int ndist = (int)round((pres+0.5)/cdist);
	pair<int, int> fir = { ps.first, pt.first }, sec = { ps.second, pt.second };
	if (fir.first > fir.second) swap(fir.first, fir.second);
	if (sec.first > sec.second) swap(sec.first, sec.second);
	rep3(i, fir.first, fir.second+1) rep3(j, sec.first, sec.second+1) {
		if (i < fir.second) dist[i][j][0] = (dist[i][j][0] + ndist + 1) / 2;
		if (j < sec.second) dist[i][j][1] = (dist[i][j][1] + ndist + 1) / 2;
	}
}
*/

using ull = unsigned long long;

void change(int k) {
	int tlim = tcnt + (k+1 + 499) / 500;
	int rcnt = 1;
	//clock_t endi_c = (clock_t)(start_c + (clock_t)(TLI * tlim * CLOCKS_PER_SEC));
	ll predist = pcalc();
	while (rcnt <= tlim) {
		int stn = -1;
		while (1) {
			stn = (int)((ll)(rand())%(30*30*2));
			if (!street[stn].empty()) break;
		}
		int stn0 = stn / (30 * 2), stn1 = stn / 2 % 30, stn2 = stn % 2;
		set<int> ptl = street[stn];
		int ptlen = ptl.size();
		int dri = (int)((ll)(rand())%20001) - 10000;
		bool neg = (dri < 0);
		double dr = 1.0 + ((double)abs(dri)/10000.0);
		int old = dist[stn0][stn1][stn2];
		int tod = (int)((!neg) ? (old * dr) : (old / dr));
		int dif = -(tod - old);
		dist[stn0][stn1][stn2] = tod;
		vector<int> chpstr;
		vector<int> oldp;
		set<int> choosed;
		for (auto itr=ptl.begin(); itr!=ptl.end(); ++itr) {
			int pi = *itr;
			int plen = path[pi].size();
			int psi = (int)((ll)(rand())%plen);
			int pstn = path[pi][psi];
			if (choosed.find(pstn) != choosed.end()) continue;
			choosed.insert(pstn);
			chpstr.push_back(pstn);
			if ((int)(chpstr.size()) > 5) break;
		}
		rep(i, (int)(chpstr.size())) {
			int pstn = chpstr[i];
			int pstn0 = pstn / (30 * 2), pstn1 = pstn / 2 % 30, pstn2 = pstn % 2;
			oldp.push_back(dist[pstn0][pstn1][pstn2]);
			dist[pstn0][pstn1][pstn2] = max(1000, min(9000, dist[pstn0][pstn1][pstn2]+(int)round((double)dif/(int)(chpstr.size()))));
		}
		ll nres = pcalc();
		if (nres <= predist) predist = nres;
		else {
			int cpsz = chpstr.size();
			rep(i, cpsz) {
				int pstn0 = chpstr[i] / (30 * 2), pstn1 = chpstr[i] / 2 % 30, pstn2 = chpstr[i] % 2;
				dist[pstn0][pstn1][pstn2] = oldp[i];
			}
			dist[stn0][stn1][stn2] = old;
		}
		++rcnt;
	}
	//cout << "k: " << tcnt << endl;
	//if (k >= 60) exit(0);
}

/*
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
*/

using pqd = pair<int, pair<pair<int, int>, char>>;

string query(pair<int, int> s, pair<int, int> t) {
	vector<vector<pair<int, char>>> disti(30, vector<pair<int, char>>(30, { INF, 'N' }));
	priority_queue<pqd, vector<pqd>, greater<pqd>> que;
	que.emplace(0, make_pair(s, 'N'));
	disti[s.first][s.second] = { 0, 'N' };
	while (!que.empty()) {
		auto p = que.top(); que.pop();
		int d = p.first, y = p.second.first.first, x = p.second.first.second;
		char c = p.second.second;
		if (disti[y][x] != make_pair(d, c)) continue;
		if (make_pair(y,x) == t) continue;
		vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
		vector<char> dc = { 'U', 'R', 'D', 'L' };
		vector<int> ddy = { -1, 0, 0, 0 }, ddx = { 0, 0, 0, -1 };
		vector<int> did = { 0, 1, 0, 1 };
		rep(i1, 4) {
			int ny = y + dy[i1], nx = x + dx[i1];
			if (ny<0 || ny>=30 || nx<0 || nx>=30) continue;
			int nd = d + dist[y+ddy[i1]][x+ddx[i1]][did[i1]];
			if (nd >= disti[ny][nx].first) continue;
			que.emplace(nd, make_pair(make_pair(ny, nx), dc[i1]));
			disti[ny][nx] = { nd, dc[i1] };
		}
	}
	pair<int, int> v = t;
	string res;
	res += disti[v.first][v.second].second;
	vector<int> dy = { 1, 0, -1, 0 }, dx = { 0, -1, 0, 1 };
	vector<char> dc = { 'U', 'R', 'D', 'L' };
	while (res.back() != 'N') {
		rep(i1, 4) if (dc[i1] == res.back()) {
			v.first += dy[i1]; v.second += dx[i1];
			break;
		}
		res += disti[v.first][v.second].second;
	}
	res.pop_back();
	reverse(all(res));
	return res;
}

void save(pair<int, int> s, pair<int, int> t, string pstr, int k) {
	vector<int> pathi;
	pair<int, int> v = s;
	vector<char> dc = { 'D', 'R', 'U', 'L' };
	vector<int> dy = { 1, 0, -1, 0 }, dx = { 0, 1, 0, -1 };
	vector<int> ddy = { 0, 0, -1, 0 }, ddx = { 0, 0, 0, -1 };
	vector<int> did = { 0, 1, 0, 1 };
	rep(i, (int)(pstr.length())) {
		int cid = -1;
		rep(j, 4) if (pstr[i] == dc[j]) { cid = j; break; }
		int stni = (v.first+ddy[cid]) * (30*2) + (v.second+ddx[cid]) * 2 + did[cid];
		street[stni].insert(k);
		pathi.push_back(stni);
		v.first += dy[cid]; v.second += dx[cid];
	}
	path.push_back(pathi);
}

/*
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
*/

ll pcalc() {
	ll sum = 0;
	int ptlen = path.size();
	int cnt = 0;
	rep(i, ptlen) {
		if (path[i].empty()) continue;
		sum += pdist(i);
		++cnt;
		if (cnt > 5) break;
	}
	return (sum * 5 / cnt);
}

ll pdist(int p) {
	vector<int> pvec = path[p];
	int plen = pvec.size();
	int sum = 0;
	rep(i, plen) {
		int pvi = pvec[i];
		int pvi0 = pvi / (30 * 2), pvi1 = pvi / 2 % 30, pvi2 = pvi % 2;
		sum += dist[pvi0][pvi1][pvi2];
	}
	ll res = (ll)abs(bans[p]-sum) * abs(bans[p]-sum);
	return res;
}

int main() {
	srand(0);
	/*
	orih = vector<vector<int>>(30, vector<int>(29));
	oriv = vector<vector<int>>(29, vector<int>(30));
	rep(i, 30) rep(j, 29) cin >> orih[i][j];
	rep(i, 29) rep(j, 30) cin >> oriv[i][j];
	start_c = clock();
	*/
	dist = vector<vector<vector<int>>>(30, vector<vector<int>>(30, vector<int>(2, 5000)));
	street = deque<set<int>>(30*30*2);
	bans = vector<int>(0);
	path = vector<vector<int>>(0);
	spos = vector<pair<int, int>>(0); tpos = vector<pair<int, int>>(0);
	tcnt = 0;
	rep(k, 1000) {
		tcnt += k;
		/*
		int si, sj, ti, tj;
		int ai; double ei;
		cin >> si >> sj >> ti >> tj >> ai >> ei;
		*/
		int si, sj, ti, tj;
		cin >> si >> sj >> ti >> tj;
		spos.emplace_back(si, sj); tpos.emplace_back(ti, tj);
		if (k-1>=0 && (k%200==100)) change(k);
		string res = query({si, sj}, {ti, tj});
		save({si, sj}, {ti, tj}, res, k);
		cout << res << endl;
		cout.flush();
		int bres;
		cin >> bres;
		//bres = (int)round((calc({si,sj}, {ti,tj}, res)) * ei);
		bans.push_back(bres);
	}
	return 0;
}
