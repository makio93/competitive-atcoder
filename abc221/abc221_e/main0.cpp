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

// 本番,未完成

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<pair<int, int>> alst(n);
	rep(i, n) alst[i] = { a[i], i };
	sort(all(alst));
	vector<int> bcnt(n+1);
	set<int> aid;
	rep(i, n) {
		if (!aid.empty()) {
			int bid = *aid.begin();
			if (bid < alst[i].second) {
				bcnt[bid]++;
				bcnt[alst[i].second]--;
			}
		}
		aid.insert(alst[i].second);
	}
	rep(i, n) bcnt[i+1] += bcnt[i];
	int lid = -1;
	mint res = 0;
	rep(i, n) {
		if (bcnt[i] > 0) {
			if (lid == -1) lid = i;
		}
		else {
			if (lid != -1) {

			}
		}
	}
	rep(i, n+1) res += mint(2).pow(i) * bcnt[i];
	cout << res.val() << endl;
	return 0;
}
