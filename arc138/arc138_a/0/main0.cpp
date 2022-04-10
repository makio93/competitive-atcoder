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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	map<int, int> aids;
	rep(i, k) {
		if (aids.find(a[i]) == aids.end()) aids[a[i]] = i;
		else aids[a[i]] = max(aids[a[i]], i);
	}
	int pid = -1;
	for (auto& pi : aids) {
		pi.second = max(pi.second, pid);
		pid = max(pid, pi.second);
	}
	int res = INF;
	rep3(i, k, n) {
		auto itr = aids.upper_bound(a[i]-1);
		if (itr != aids.begin()) {
			--itr;
			res = min(res, (k-(itr->second))+(i-k));
		}
	}
	if (res == INF) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
