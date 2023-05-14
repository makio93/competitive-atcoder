// 本番WA

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
	string s;
	ll n;
	cin >> s >> n;
	int slen = s.length();
	auto zs = s;
	rep(i, slen) if (zs[i] == '?') zs[i] = '0';
	if (stoll(zs) > n) {
		cout << -1 << endl;
		return 0;
	}
	int dlen = 0;
	rep(i, 61) if (n&(1LL<<i)) dlen = i;
	if (dlen > slen) {
		rep(i, slen) if (s[slen-1-i] == '?') s[slen-1-i] = '1';
		ll res = 0;
		rep(i, slen) {
			res *= 2;
			res += s[i] - '0';
		}
		cout << res << endl;
		return 0;
	}
	auto dfs = [&](auto& dfs, int di, ll val) -> ll {
		if (val > n) return -1;
		if (di == 0) {
			if (s[slen-1] != '0') {
				if (val+1 <= n) return val+1;
				else if (s[slen-1] == '1') return val;
			}
			else if (val <= n) return val;
		}
		if (s[slen-1-di] != '0') {
			ll nval = val + (1LL << di);
			if (dfs(dfs, di-1, nval) != -1) return nval;
			else if (s[slen-1-di] == '1') return -1;
		}
		else return dfs(dfs, di-1, val);
	};
	ll rval = dfs(dfs, dlen, 0);
	cout << rval << endl;
	return 0;
}
