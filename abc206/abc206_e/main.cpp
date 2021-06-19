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

int main() {
	int l, r;
	cin >> l >> r;
	ll res = 0;
	rep3(i, l, r) {
		if (i <= 2) continue;
		vector<ll> pi;
		ll val = i;
		for (ll j=2; j*j<=val; ++j) {
			while (val%j == 0) {
				pi.push_back(j);
				val /= j;
			}
		}
		if (val > 1LL) pi.push_back(val);
		if ((int)(pi.size()) <= 1) continue;
		sort(all(pi));
		pi.erase(unique(all(pi)), pi.end());
		int len = pi.size();
		val = i;
		rep(i1, len) {
			ll val1 = pi[i1];
			ll val2 = val / val1;
			//if (val1==1) continue;
			//if (val2 < val1-1) continue;
			if (r/val1 < val2+1) continue;
			ll sub = ((ll)r / val1) / val2 - 1;
			ll add = ((ll)r / val1) - val2;
			if (add < 0) continue;
			res += (add - sub) * 2;
		}
	}
	cout << res << endl;
	return 0;
}
