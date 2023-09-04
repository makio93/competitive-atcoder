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
	vector<bool> weaker(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		weaker[bi] = true;
	}
	if (count(all(weaker), false) > 1) cout << -1 << endl;
	else {
		int res = find(all(weaker), false) - weaker.begin() + 1;
		cout << res << endl;
	}
	return 0;
}
