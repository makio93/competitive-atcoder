// 本番TLE

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
	vector<int> vcnt(10);
	rep(i, n) vcnt[s[i]-'0']++;
	ll mx = 1;
	rep(i, n) mx *= 10;
	set<ll> sst;
	for (ll i=0; i*i<=mx; ++i) sst.insert(i*i);
	ll res = 0;
	function<void(int, ll)> f = [&](int di, ll val) {
		if (di == n) {
			if (sst.find(val) != sst.end()) ++res;
			return;
		}
		rep(i, 10) {
			if (vcnt[i] == 0) continue;
			vcnt[i]--;
			f(di+1, val*10+i);
			vcnt[i]++;
		}
	};
	f(0, 0);
	cout << res << endl;
	return 0;
}
