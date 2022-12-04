// 自力AC

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

int main() {
	ll k;
	cin >> k;
	vector<pair<ll, int>> plst;
	ll tk = k;
	for (ll i=2; i*i<=tk; ++i) if (tk%i == 0) {
		plst.emplace_back(i, 0);
		while (tk%i == 0) {
			tk /= i;
			plst.back().second++;
		}
	}
	if (tk > 1) plst.emplace_back(tk, 1);
	ll lv = 1, rv = k;
	while (rv-lv > 1) {
		ll cv = rv - (rv-lv) / 2;
		bool ok = true;
		for (const auto& pi : plst) {
			ll pv = 1, pcnt = 0;
			while (pv <= cv/pi.first) {
				pv *= pi.first;
				pcnt += cv / pv;
			}
			if (pcnt < pi.second) {
				ok = false;
				break;
			}
		}
		if (ok) rv = cv;
		else lv = cv;
	}
	cout << rv << endl;
	return 0;
}
