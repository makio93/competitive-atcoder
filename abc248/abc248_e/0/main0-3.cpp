// 本番WA3

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
	int n, k;
	cin >> n >> k;
	vector<ll> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	if (k == 1) {
		cout << "Infinity" << endl;
		return 0;
	}
	vector<int> ids(n);
	iota(all(ids), 0);
	sort(all(ids), [&](int id1, int id2){
		if (x[id1] != x[id2]) return x[id1] < x[id2];
		else return y[id1] < y[id2];
	});
	map<pair<double, double>, int> cnt;
	rep(i, n) rep3(j, i+1, n) if (x[ids[i]]!=x[ids[j]] && y[ids[i]]!=y[ids[j]]) {
		ll ay = y[ids[j]] - y[ids[i]], ax = x[ids[j]] - x[ids[i]];
		double af = ay / (double)ax;
		double by = y[ids[i]] + (double)(-x[ids[i]])*af;
		cnt[{af, by}]++;
	}
	int res = 0;
	for (auto& pi : cnt) if (pi.second >= k-1) ++res;
	unordered_map<ll, int> ycnt, xcnt;
	rep(i, n) ycnt[x[i]]++;
	for (auto& pi : ycnt) if (pi.second >= k) ++res;
	rep(i, n) xcnt[y[i]]++;
	for (auto& pi : xcnt) if (pi.second >= k) ++res;
	cout << res << endl;
	return 0;
}
