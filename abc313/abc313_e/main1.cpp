// 解説AC

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

const ll mod = 998244353LL;

int main() {
	int n;
	string s;
	cin >> n >> s;
	bool ok = true;
	rep(i, n-1) if (s[i] != '1' && s[i+1] != '1') ok = false;
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	vector<pair<int, int>> sl;
	sl.emplace_back(s[0]-'0', 1);
	rep3(i, 1, n) {
		if (s[i]-'0' == sl.back().first) sl.back().second++;
		else sl.emplace_back(s[i]-'0', 1);
	}
	int m = sl.size();
	ll res = 0;
	repr(i, m) {
		ll add = sl[i].second - (i == 0 ? 1 : 0);
		if (sl[i].first == 1 && i+1 < m) add = (add + res * (sl[i+1].first - 1)) % mod;
		res = (res + add) % mod;
	}
	cout << res << endl;
	return 0;
}
