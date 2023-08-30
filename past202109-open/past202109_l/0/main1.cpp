// 解説AC

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
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> s(n+1);
	rep(i, n) s[i+1] += s[i] + a[i];
	sort(all(s));
	ll lv = -1, rv = LINF;
	while (rv-lv > 1) {
		ll cv = lv + (rv-lv) / 2, cnt = 0;
		int li = 0, ri = 0;
		rep(i, n+1) {
			while (li<n+1 && s[i]-s[li]>cv) ++li;
			while (ri+1<n+1 && s[ri+1]-s[i]<=cv) ++ri;
			cnt += max(0, ri-li); 
		}
		if (cnt < k*2) lv = cv;
		else rv = cv;
	}
	cout << rv << endl;
	return 0;
}
