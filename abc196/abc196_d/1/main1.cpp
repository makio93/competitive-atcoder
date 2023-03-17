// 学習1回目,解説AC

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
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	int res = 0;
	auto dfs = [&](auto dfs, int id, int bt, int ai, int bi) -> void {
		if (id == h*w) {
			++res;
			return;
		}
		if (bt&(1<<id)) return dfs(dfs, id+1, bt, ai, bi);
		if (bi > 0) dfs(dfs, id+1, bt|(1<<id), ai, bi-1);
		if (ai > 0) {
			if (id%w!=w-1 && (~bt&(1<<(id+1)))) dfs(dfs, id+1, bt|(1<<id)|(1<<(id+1)), ai-1, bi);
			if (id/w!=h-1 && (~bt&(1<<(id+w)))) dfs(dfs, id+1, bt|(1<<id)|(1<<(id+w)), ai-1, bi);
		}
	};
	dfs(dfs, 0, 0, a, b);
	cout << res << endl;
	return 0;
}
