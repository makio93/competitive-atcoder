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

// 本番実装,TLE2

using mint = modint998244353;

int n, d;
vector<int> a;

map<vector<bool>, unordered_map<int, mint>> memo;
mint calc(vector<bool>& st, int dep=0) {
	if (memo.find(st)!=memo.end() && memo[st].find(dep)!=memo[st].end()) return memo[st][dep];
	if (dep == n) return (memo[st][dep] = 1);
	else if (a[dep] != -1) return (memo[st][dep] = calc(st, dep+1));
	else {
		mint res = 0;
		int lval = max(0, dep-d), rval = min(n-1, dep+d) + 1;
		rep3(i, lval, rval) if (st[i]) {
			st[i] = false;
			res += calc(st, dep+1);
			st[i] = true;
		}
		return (memo[st][dep] = res);
	}
}

int main() {
	cin >> n >> d;
	a = vector<int>(n);
	rep(i, n) {
		cin >> a[i];
		if (a[i] != -1) a[i]--;
	}
	vector<bool> st(n);
	rep(i, n) st[i] = true;
	rep(i, n) if (a[i] != -1) st[a[i]] = false;
	mint res = calc(st);
	cout << res.val() << endl;
	return 0;
}
