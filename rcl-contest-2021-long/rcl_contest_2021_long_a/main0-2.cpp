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

int main() {
	int n, m, t;
	cin >> n >> m >> t;
	vector<int> ri(m), ci(m), si(m), ei(m), vi(m);
	rep(i, m) cin >> ri[i] >> ci[i] >> si[i] >> ei[i] >> vi[i];
	vector<map<pair<int, int>, int>> slst(t), elst(t);
	rep(i, m) slst[si[i]][{ri[i],ci[i]}] = i;
	rep(i, m) elst[ei[i]][{ri[i],ci[i]}] = i;
	vector<vector<ll>> vcnt(n, vector<ll>(n));
	rep(i, m) vcnt[ri[i]][ci[i]] += vi[i];
	vector<pair<ll, pair<int, int>>> vlst;
	rep(i, n) rep(j, n) vlst.emplace_back(vcnt[i][j], make_pair(i, j));
	sort(vlst.rbegin(), vlst.rend());
	vector<vector<int>> board(n, vector<int>(n, -1));
	ll nval = 1;
	int mcnt = 0, moved = -1;
	pair<int, int> tpos = { -1, -1 };
	rep(i, t) {
		vector<int> res;
		for (auto p : slst[i]) board[p.first.first][p.first.second] = p.second;
		if (i<t/2 && moved==-1 && mcnt<n*n && nval>=(ll)(mcnt+1)*(mcnt+1)*(mcnt+1)) {
			nval -= (ll)(mcnt+1)*(mcnt+1)*(mcnt+1);
			res.push_back(vlst[mcnt].second.first);
			res.push_back(vlst[mcnt].second.second);
			++mcnt;
		}
		if (moved==-1 && res.empty()) {
			vector<int> mlst;
			auto tb = board;
			rep(j, mcnt) {
				if (tb[vlst[j].second.first][vlst[j].second.second] == -1) mlst.push_back(j);
				else tb[vlst[j].second.first][vlst[j].second.second] = -1;
			}
			if (!mlst.empty()) {
				pair<int, pair<int, int>> mval = { -1, { -1, -1 } };
				rep(i2, n) rep(j2, n) if (tb[i2][j2] != -1) mval = max(mval, { vi[tb[i2][j2]], { i2, j2 } });
				if (mval.first != -1) {
					moved = mlst.front();
					tpos = mval.second;
					res.push_back(vlst[moved].second.first);
					res.push_back(vlst[moved].second.second);
					res.push_back(tpos.first);
					res.push_back(tpos.second);
				}
			}
		}
		else if (moved!=-1 && res.empty()) {
			res.push_back(tpos.first);
			res.push_back(tpos.second);
			res.push_back(vlst[moved].second.first);
			res.push_back(vlst[moved].second.second);
			tpos = { -1, -1 };
			moved = -1;
		}
		rep(j, mcnt) {
			if (moved == j) {
				if (board[tpos.first][tpos.second] != -1) {
					nval += vi[board[tpos.first][tpos.second]];
					board[tpos.first][tpos.second] = -1;
				}
			}
			else {
				if (board[vlst[j].second.first][vlst[j].second.second] != -1) {
					nval += vi[board[vlst[j].second.first][vlst[j].second.second]];
					board[vlst[j].second.first][vlst[j].second.second] = -1;
				}
			}
		}
		if (res.empty()) res.push_back(-1);
		for (auto p : elst[i]) board[p.first.first][p.first.second] = -1;
		int rlen = res.size();
		rep(j, rlen) printf("%d%c", res[j], (j<rlen-1?' ':'\n'));
	}
	//cout << "score: " << nval << endl;
	return 0;
}
