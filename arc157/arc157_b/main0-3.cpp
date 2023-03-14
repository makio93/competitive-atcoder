// 自力AC

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
	int n, k;
	string s;
	cin >> n >> k >> s;
	int xcnt = count(all(s), 'X');
	if (xcnt < k) {
		rep(i, n) {
			if (s[i] == 'X') s[i] = 'Y';
			else s[i] = 'X';
		}
		xcnt = count(all(s), 'X');
		k = n - k;
	}
	vector<pair<char, int>> rlst;
	rlst.emplace_back(s[0], 1);
	rep3(i, 1, n) {
		if (s[i] == rlst.back().first) rlst.back().second++;
		else rlst.emplace_back(s[i], 1);
	}
	int res = 0, m = rlst.size();
	if (m == 1) {
		if (rlst[0].first == 'X') res = max(0, k-1);
		else res = n - 1;
	}
	else {
		vector<int> xlst;
		rep3(i, 1, m-1) if (rlst[i].first == 'X') xlst.push_back(rlst[i].second);
		rep(i, m) if (rlst[i].first == 'Y') res += rlst[i].second - 1;
		sort(all(xlst));
		int xlen = xlst.size();
		rep(i, xlen) {
			if (k == 0) break;
			if (xlst[i] <= k) {
				res += xlst[i] + 1;
				k -= xlst[i];
			}
			else {
				res += k;
				k = 0;
			}
		}
		res += k;
	}
	cout << res << endl;
	return 0;
}
