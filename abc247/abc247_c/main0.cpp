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
	cin >> n;
	map<int, vector<int>> memo;
	auto s = [&](auto s, int val) {
		if (memo.find(val) != memo.end()) return memo[val];
		vector<int> ret;
		if (val == 1) {
			ret.push_back(1);
			return memo[val] = ret;
		}
		else {
			auto ps = s(s, val-1);
			for (int pval : ps) ret.push_back(pval);
			ret.push_back(val);
			for (int pval : ps) ret.push_back(pval);
			return memo[val] = ret;
		}
	};
	auto vlst = s(s, n);
	int m = vlst.size();
	rep(i, m) printf("%d%c", vlst[i], (i<m-1?' ':'\n'));
	return 0;
}
