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
	ll n;
	cin >> n;
	vector<ll> plst;
	ll plen = 1;
	for (ll i=1; i*i*i<=n; ++i) plen = i;
	vector<bool> used(plen+1);
	for (ll i=2; i<=plen; ++i) {
		if (!used[i]) {
			plst.push_back(i);
			for (ll j=i*2; j<=plen; j+=i) used[j] = true;
		}
	}
	int m = plst.size();
	ll res = 0;
	rep(i, m) {
		int len = upper_bound(all(plst), n/(plst[i]*plst[i]*plst[i])) - plst.begin();
		len = min(len, i);
		res += len;
	}
	cout << res << endl;
	return 0;
}
