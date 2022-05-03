// 自力AC2

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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll res = LINF;
	rep(i, (1<<n)) if (__builtin_popcount(i) == k) {
		auto b = a;
		int mval = 0;
		ll sum = 0;
		rep(j, n) {
			if (((i>>j)&1) && mval>=b[j]) {
				sum += mval+1-b[j];
				b[j] = mval + 1;
			}
			mval = max(mval, b[j]);
		}
		res = min(res, sum);
	}
	cout << res << endl;
	return 0;
}
