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

using mint = modint998244353;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<unordered_map<int, mint>> memo(n+1);
	auto dfs = [&](auto dfs, int di, int ki) -> mint {
		if (memo[di].find(ki) != memo[di].end()) return memo[di][ki];
		if (di == n) {
			if (ki >= 0) return memo[di][ki] = 1;
			else return memo[di][ki] = 0;
		}
		if (ki <= 0) return memo[di][ki] = 0;
		mint res = 0;
		rep3(i, 1, m+1) {
			if (i > ki) break;
			res += dfs(dfs, di+1, ki-i);
		}
		return memo[di][ki] = res;
	};
	cout << dfs(dfs, 0, k).val() << endl;
	return 0;
}
