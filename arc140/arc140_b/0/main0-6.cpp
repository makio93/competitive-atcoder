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

const int INF = (int)(1e9);

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<pair<char, int>> runs;
	runs.emplace_back(s[0], 1);
	rep3(i, 1, n) {
		if (runs.back().first == s[i]) runs.back().second++;
		else runs.emplace_back(s[i], 1);
	}
	vector<int> rlst;
	int m = runs.size();
	rep3(i, 1, m-1) if (runs[i].first=='R' && runs[i].second==1) {
		if (runs[i-1].first=='A' && runs[i+1].first=='C') 
			rlst.push_back(min(runs[i-1].second, runs[i+1].second));
	}
	if (rlst.empty()) {
		cout << 0 << endl;
		return 0;
	}
	sort(all(rlst));
	int k = rlst.size();
	int lcnt = k, rcnt = 0;
	rep(i, k) rcnt += rlst[i] - 1;
	int res = 0;
	if (rcnt > lcnt) res = lcnt * 2;
	else res = rcnt + lcnt;
	cout << res << endl;
	return 0;
}
