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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll x;
	cin >> x;
	ll sum = 0;
	rep(i, n) sum += a[i];
	ll rcnt = x / sum, rval = x % sum;
	vector<ll> sval(n+1);
	rep(i, n) sval[i+1] = sval[i] + a[i];
	int di = upper_bound(all(sval), rval) - sval.begin();
	ll res = rcnt * n + di;
	cout << res << endl;
	return 0;
}
