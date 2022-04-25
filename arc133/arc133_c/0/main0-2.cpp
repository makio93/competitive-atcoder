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

// 本番WA2

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	vector<int> a(h), b(w);
	rep(i, h) cin >> a[i];
	rep(i, w) cin >> b[i];
	if (h > w) {
		swap(h, w);
		swap(a, b);
	}
	vector<int> hcnt, wcnt;
	ll res = 0, hsum = (ll)(k-1) * (w-h), wsum = 0;
	rep(i, h) {
		int hval = (int)(((a[i]+k) - (ll)(k-1)*(w-1) % k) % k);
		hcnt.push_back(hval);
		res += (ll)(k-1)*(w-1) + hval;
		hsum += hval;
	}
	rep(i, w) {
		int wval = (int)(((b[i]+k) - (ll)(k-1)*(h-1) % k) % k);
		wcnt.push_back(wval);
		wsum += wval;
	}
	if ((hsum-wsum)%k!=0) {
		cout << -1 << endl;
		return 0;
	}
	res -= abs(hsum-wsum);
	cout << res << endl;
	return 0;
}
