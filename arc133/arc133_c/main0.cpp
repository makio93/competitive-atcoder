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

// 本番WA1

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
	map<int, int> hcnt, wcnt;
	ll res = 0;
	rep(i, h) {
		int hval = (int)(((a[i]+k) - (ll)(k-1)*(w-1) % k) % k);
		hcnt[hval]++;
		res += (ll)(k-1)*(w-1) + hval;
	}
	rep(i, w) {
		int wval = (int)(((b[i]+k) - (ll)(k-1)*(h-1) % k) % k);
		wcnt[wval]++;
	}
	bool ok = true;
	for (auto hpi : hcnt) {
		if (wcnt.find(hpi.first) == wcnt.end()) ok = false;
		else if (wcnt[hpi.first] < hpi.second) ok = false;
		else {
			wcnt[hpi.first] -= hpi.second;
			if (wcnt[hpi.first] == 0) wcnt.erase(hpi.first);
		}
		if (!ok) break;
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	ll hsum = (ll)(k-1) * (w-h), wsum = 0;
	for (auto wpi : wcnt) wsum += (ll)wpi.first * wpi.second;
	if ((hsum-wsum)%k != 0) ok = false;
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	res -= hsum-wsum;
	cout << res << endl;
	return 0;
}
