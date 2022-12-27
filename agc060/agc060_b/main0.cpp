// 本番AC

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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m, k;
		string s;
		cin >> n >> m >> k >> s;
		int slen = s.length();
		vector<vector<int>> b(n, vector<int>(m, -1));
		int yi = 0, xi = 0;
		b[yi][xi] = 0;
		rep(i, slen) {
			if (s[i] == 'R') ++xi;
			else ++yi;
			b[yi][xi] = 0;
		}
		vector<pair<char, int>> clst;
		clst.emplace_back(s[0], 1);
		rep3(i, 1, slen) {
			if (clst.back().first == s[i]) clst.back().second++;
			else clst.emplace_back(s[i], 1);
		}
		int clen = clst.size();
		yi = 0, xi = 0;
		rep(i, clen-1) {
			if (clst[i].first == 'R') {
				xi += clst[i].second;
				int li = xi - clst[i].second, tyi = yi + 1, txi = xi - 1;
				while (txi>=0 && tyi<n && txi>=li) {
					b[tyi][txi] = 1;
					++tyi; --txi;
				}
			}
			else {
				yi += clst[i].second;
				int ui = yi - clst[i].second, tyi = yi - 1, txi = xi + 1;
				while (txi<m && tyi>=0 && tyi>=ui) {
					b[tyi][txi] = 1;
					--tyi; ++txi;
				}
			}
		}
		vector<vector<int>> dist(n, vector<int>(m, -INF));
		dist[0][0] = 0;
		rep(i, n) rep(j, m) {
			if (j+1 < m) {
				if (b[i][j+1] != 1) chmax(dist[i][j+1], dist[i][j]);
				else chmax(dist[i][j+1], dist[i][j]+1);
			}
			if (i+1 < n) {
				if (b[i+1][j] != 1) chmax(dist[i+1][j], dist[i][j]);
				else chmax(dist[i+1][j], dist[i][j]+1);
			}
		}
		if (dist[n-1][m-1] <= k) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
