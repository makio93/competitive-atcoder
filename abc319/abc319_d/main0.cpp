// 本番AC

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
	int n, m;
	cin >> n >> m;
	vector<int> l(n);
	rep(i, n) cin >> l[i];
	ll lv = 0, rv = accumulate(all(l), 0LL) + n;
	while (rv-lv > 1) {
		ll cv = rv - (rv-lv) / 2, val = 0;
		bool ng = false;
		int cnt = 0;
		rep(i, n) {
			if (l[i] > cv) {
				ng = true;
				break;
			}
			if (val == 0) {
				val += l[i];
				++cnt;
			}
			else if (val+1+l[i] <= cv) val += l[i] + 1;
			else {
				val = l[i];
				++cnt;
			}
		}
		if (ng || cnt>m) lv = cv;
		else rv = cv;
	}
	cout << rv << endl;
	return 0;
}
