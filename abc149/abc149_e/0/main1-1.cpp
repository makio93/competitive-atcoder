// 解説AC1

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
	ll m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int am = *max_element(all(a));
	vector<int> acnt(am+2);
	rep(i, n) acnt[a[i]]++;
	repr(i, am+1) acnt[i] += acnt[i+1];
	int lval = 1, rval = am*2+1;
	while (rval-lval > 1) {
		int cval = rval - (rval-lval) / 2;
		ll cnt = 0;
		rep(i, n) {
			int tval = max(0, min(am+1, cval-a[i]));
			cnt += acnt[tval];
		}
		if (cnt <= m) rval = cval;
		else lval = cval;
	}
	vector<ll> ssum(am+2);
	repr(i, am+1) ssum[i] = ssum[i+1] + (acnt[i]-acnt[i+1]) * (ll)i;
	ll res = 0;
	rep(i, n) {
		int tval = max(0, min(am+1, rval-a[i]));
		res += ssum[tval] + (ll)a[i] * acnt[tval];
		m -= acnt[tval];
	}
	res += m * lval;
	cout << res << endl;
	return 0;
}
