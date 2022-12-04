// 自力WA

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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> c(n);
		rep(i, n) {
			cin >> c[i];
			c[i]--;
		}
		vector<int> ccnt(n);
		rep(i, n) ccnt[c[i]]++;
		vector<pair<int, int>> cp;
		rep(i, n) if (ccnt[i] > 0) cp.emplace_back(ccnt[i], i);
		sort(cp.rbegin(), cp.rend());
		vector<int> clst;
		for (const auto& pi : cp) rep(i, pi.first) clst.push_back(pi.second);
		int llen = (n+1) / 2, ri = n - 1;
		vector<int> res;
		rep(i, llen) {
			res.push_back(clst[i]+1);
			if (ri > i) {
				res.push_back(clst[ri]+1);
				--ri;
			}
		}
		rep(i, n) cout << res[i] << ' ';
		cout << endl;
	}
	return 0;
}
