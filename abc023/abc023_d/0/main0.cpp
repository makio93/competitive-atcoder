// 練習0,自力AC

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
	cin >> n;
	vector<int> h(n), s(n);
	rep(i, n) cin >> h[i] >> s[i];
	int hval = 0, sval = 0;
	rep(i, n) {
		hval = max(hval, h[i]);
		sval = max(sval, s[i]);
	}
	ll l = hval, r = hval + (ll)sval * n + 1;
	while (r-l > 0) {
		ll c = l + (r-l) / 2;
		vector<int> cnt(n);
		rep(i, n) {
			int id = (int)min((ll)n-1, (c-h[i])/s[i]);
			cnt[id]++;
		}
		rep(i, n-1) cnt[i+1] += cnt[i];
		bool ok = true;
		rep(i, n) if (cnt[i] > i+1) ok = false;
		if (ok) r = c;
		else l = c+1;
	}
	cout << r << endl;
	return 0;
}
