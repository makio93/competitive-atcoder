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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int>> aids(n);
	rep(i, n) aids[a[i]].push_back(i);
	ll res = 0;
	rep(i, n/2) {
		int li = i, ri = n - 1 - i;
		int lcnt = upper_bound(all(aids[a[li]]), ri) - lower_bound(all(aids[a[li]]), li) - 1;
		res += (ll)(ri - li - lcnt) * (i+1);
		int rcnt = lower_bound(all(aids[a[ri]]), ri) - lower_bound(all(aids[a[ri]]), li+1);
		res += (ll)(ri - li - 1 - rcnt) * (i+1);
	}
	cout << res << endl;
	return 0;
}
