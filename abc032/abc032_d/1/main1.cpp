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

const ll LINF = (ll)(1e18);

int main() {
	int n, w;
	cin >> n >> w;
	vector<int> vi(n), wi(n);
	rep(i, n) cin >> vi[i] >> wi[i];
	int vmx = *max_element(all(vi)), wmx = *max_element(all(wi));
	ll res = 0;
	if (n <= 30) {
		set<pair<ll, ll>> lst;
		rep(i, 1<<(n/2)) {
			ll val = 0, wei = 0;
			rep(j, n/2) if (i&(1<<j)) {
				val += vi[j];
				wei += wi[j];
			}
			lst.emplace(wei, val);
		}
		for (auto itr=next(lst.begin()); itr!=lst.end(); ++itr) if (prev(itr)->second >= itr->second) itr = prev(lst.erase(itr));
		rep(i, 1<<(n-n/2)) {
			ll val = 0, wei = 0;
			rep(j, n-n/2) if (i&(1<<j)) {
				val += vi[n/2+j];
				wei += wi[n/2+j];
			}
			if (wei > w) continue;
			auto itr = lst.upper_bound({ w-wei, LINF });
			if (itr != lst.begin()) res = max(res, val+prev(itr)->second);
		}
	}
	else if (wmx <= 1000) {
		vector<ll> dp(wmx*n+1, -LINF);
		dp[0] = 0;
		rep(i, n) repr(j, wmx*n) if (dp[j]!=-LINF && j+wi[i]<=wmx*n) dp[j+wi[i]] = max(dp[j+wi[i]], dp[j]+vi[i]);
		rep(i, w+1) {
			if (i >= wmx*n+1) break;
			res = max(res, dp[i]);
		}
	}
	else {
		vector<ll> dp(vmx*n+1, LINF);
		dp[0] = 0;
		rep(i, n) repr(j, vmx*n) if (dp[j]!=LINF && j+vi[i]<=vmx*n) dp[j+vi[i]] = min(dp[j+vi[i]], dp[j]+wi[i]);
		rep(i, vmx*n+1) if (dp[i]!=LINF && dp[i]<=w) res = max(res, (ll)i);
	}
	cout << res << endl;
	return 0;
}
