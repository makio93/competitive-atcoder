// 本番

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
	int lid = 0, rid = k - 1;
	int res = 0;
	stack<int> lval;
	while (rid >= lid) {
		while (rid>=lid && rlst[rid]<=1) {
			if (rlst[rid] == 1) {
				rlst[rid] = 0;
				lval.push(1);
			}
			--rid;
		}
		if (rid < lid) break;
		rlst[rid]--;
		++res;
		if (!lval.empty()) {
			lval.pop();
			++res;
		}
		else {
			if (rlst[lid] == 0) break;
			++res;
			rlst[lid] = 0;
			++lid;
		}
	}
	if (!lval.empty()) res += lval.size();
	cout << res << endl;
	return 0;
}
