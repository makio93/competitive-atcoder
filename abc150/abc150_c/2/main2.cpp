// 学習1,解説AC,解法2

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

int main() {
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, n) {
		cin >> q[i];
		q[i]--;
	}
	auto dfs = [&](auto dfs, vector<int>& per, vector<int>& tar, int d=0) -> int {
		int res = 0;
		if (d == n) {
			if (per <= tar) return 1;
			else return res;
		}
		rep(i, n) if (find(all(per), i) == per.end()) {
			per[d] = i;
			int rev = dfs(dfs, per, tar, d+1);
			if (rev == -1) return res;
			res += rev;
			per[d] = -1;
		}
		return res;
	};
	vector<int> x(n, -1);
	int a = dfs(dfs, x, p);
	x = vector<int>(n, -1);
	int b = dfs(dfs, x, q);
	cout << abs(a-b) << endl;
	return 0;
}
