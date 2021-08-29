#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	map<ll, int> acnt;
	rep(i, n) acnt[a[i]]++;
	vector<pair<ll, int>> rsum;
	int sum = 0;
	for (auto itr=acnt.rbegin(); itr!=acnt.rend(); ++itr) {
		sum += itr->second;
		rsum.emplace_back(itr->first, sum);
	}
	rsum.emplace_back(0, n);
	int len = rsum.size();
	ll res = 0;
	rep(i, len-1) {
		ll a = rsum[i].first, b = rsum[i+1].first + 1;
		int rval = rsum[i].second;
		ll scost = (ll)(a-b+1) * rval;
		if (k >= scost) {
			ll asub = (a + b) * (a-b+1) / 2 * rval;
			res += asub;
			k -= scost;
		}
		else {
			ll sublen = k / rval;
			ll subcost = sublen * rval;
			k -= subcost;
			ll b2 = a - sublen + 1;
			ll bsub = (a + b2) * (a-b2+1) / 2 * rval;
			res += bsub;
			res += (b2-1) * k;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
