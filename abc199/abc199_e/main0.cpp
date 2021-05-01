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

// 本番終了後、自力で実装、WA

const int INF = (int)(1e9);

map<pair<vector<int>, int>, ll> memo;
ll calc(vector<int>& perm, vector<vector<int>>& c, int d=0) {
	if (memo.find({perm,d}) != memo.end()) return memo[{perm,d}];
	int n = perm.size();
	if (d == n) return (memo[{perm,d}] = 1LL);
	else {
		ll res = 0;
		if (d+1 > c.back()[0]) {
			res = 1;
			rep3(i, 1, (n-d)+1) res *= i;
			return (memo[{perm,d}] = res);
		}
		rep3(i, 1, n+1) {
			bool exist = false;
			rep(j, d) if (perm[j] == i) exist = true;
			if (exist) continue;
			perm[d] = i;
			bool ok = true;
			for (auto p : c) {
				if (p[0] < d+1) continue;
				int cnt = 0;
				rep(j, d+1) if (perm[j] <= p[1]) ++cnt;
				if (cnt > p[2]) {
					ok = false;
					break;
				}
			}
			if (ok) res += calc(perm, c, d+1);
			else perm[d] = INF;
		}
		return (memo[{perm,d}] = res);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	if (m == 0) {
		ll res = 1;
		rep3(i, 1, n+1) res *= i;
		cout << res << endl;
		return 0;
	}
	vector<vector<int>> c;
	rep(i, m) {
		int xi, yi, zi;
		cin >> xi >> yi >> zi;
		if (zi>=xi || zi>=yi) continue;
		c.push_back({ xi, yi, zi });
	}
	sort(all(c));
	vector<int> perm(n, INF);
	cout << calc(perm, c) << endl;
	return 0;
}
