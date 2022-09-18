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
	vector<int> bids;
	rep(i, 60) if (n&(1LL<<i)) bids.push_back(i);
	vector<ll> res;
	int len = bids.size();
	rep(i, 1<<len) {
		ll val = 0;
		rep(j, len) if (i&(1<<j)) val += 1LL << bids[j];
		res.push_back(val); 
	}
	sort(all(res));
	int rlen = res.size();
	rep(i, rlen) cout << res[i] << endl;
	return 0;
}
