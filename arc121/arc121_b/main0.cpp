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

const string col = "RGB";

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> acal(3);
	rep(i, 2*n) {
		ll ai;
		char ci;
		cin >> ai >> ci;
		rep(j, 3) if (ci == col[j]) {
			acal[j].push_back(ai);
			break;
		}
	}
	vector<int> odd;
	rep(i, 3) if ((int)(acal[i].size())%2 != 0) odd.push_back(i);
	if (odd.empty()) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, 3) sort(all(acal[i]));
	ll mval = (ll)(1e18);
	rep(i, (int)(acal[odd[0]].size())) {
		int id1 = lower_bound(all(acal[odd[1]]), acal[odd[0]][i]) - acal[odd[1]].begin();
		if (id1 < (int)(acal[odd[1]].size())) mval = min(mval, llabs(acal[odd[1]][id1]-acal[odd[0]][i]));
		if (id1-1 >= 0) mval = min(mval, llabs(acal[odd[1]][id1-1]-acal[odd[0]][i]));
	}
	int even = 0;
	rep(i, 2) if (even == odd[i]) ++even;
	if (!acal[even].empty()) {
		vector<pair<ll, int>> mval2(2, {(ll)(1e18), -1});
		rep(i1, 2) {
			rep(i, (int)(acal[odd[i1]].size())) {
				int id1 = lower_bound(all(acal[even]), acal[odd[i1]][i]) - acal[even].begin();
				if (id1 < (int)(acal[even].size())) mval2[i1] = min(mval2[i1], {llabs(acal[even][id1]-acal[odd[i1]][i]),id1});
				if (id1-1 >= 0) mval2[i1] = min(mval2[i1], {llabs(acal[even][id1-1]-acal[odd[i1]][i]),id1-1});
			}
		}
		if (mval2[0].second != mval2[1].second) mval = min(mval, mval2[0].first+mval2[1].first);
	}
	cout << mval << endl;
	return 0;
}
