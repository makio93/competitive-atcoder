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

// 本番実装,TLE1

using mint = modint998244353;

int n, d;
vector<int> a;

map<pair<set<int>, int>, mint> memo;
mint calc(set<int>& st, int dep=0) {
	if (memo.find({st, dep}) != memo.end()) return memo[{st, dep}];
	if (dep == n) return (memo[{st, dep}] = 1);
	else if (a[dep] != -1) return (memo[{st, dep}] = calc(st, dep+1));
	else {
		mint res = 0;
		int lval = max(0, dep-d), rval = min(n-1, dep+d) + 1;
		auto sitr = st.lower_bound(lval);
		while (sitr!=st.end() && (*sitr)<rval) {
			int tval = *sitr;
			sitr = st.erase(sitr);
			res += calc(st, dep+1);
			sitr = st.insert(tval).first;
			++sitr;
		}
		return (memo[{st, dep}] = res);
	}
}

int main() {
	cin >> n >> d;
	a = vector<int>(n);
	rep(i, n) {
		cin >> a[i];
		if (a[i] != -1) a[i]--;
	}
	set<int> st;
	rep(i, n) st.insert(i);
	rep(i, n) if (a[i] != -1) st.erase(a[i]);
	mint res = calc(st);
	cout << res.val() << endl;
	return 0;
}
