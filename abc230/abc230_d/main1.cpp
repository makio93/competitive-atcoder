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

// 解説AC

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> l(n), r(n);
	rep(i, n) cin >> l[i] >> r[i];
	vector<pair<int, int>> rl(n);
	rep(i, n) rl[i] = { r[i], l[i] };
	sort(all(rl));
	int res = 0, lpos = (int)(-1.5e9);
	rep(i, n) {
		if (rl[i].second > lpos+d-1) {
			lpos = rl[i].first;
			++res;
		}
	}
	cout << res << endl;
	return 0;
}
