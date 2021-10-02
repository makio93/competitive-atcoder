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
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	map<ll, int> cal;
	cal[0] = 0;
	rep(i, n) {
		ll li = a[i], ri = li + b[i];
		cal[li]++; cal[ri]--;
	}
	vector<ll> res(n+1);
	int nval = 0;
	for (auto itr=next(cal.begin()); itr!=cal.end(); ++itr) {
		auto pitr = prev(itr);
		if (nval > 0) res[nval] += itr->first - pitr->first;
		nval += itr->second;
	}
	rep3(i, 1, n+1) printf("%lld%c", res[i], (i<n?' ':'\n'));
	return 0;
}
