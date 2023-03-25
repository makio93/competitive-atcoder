// バチャ本番,自力AC

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
	vector<pair<int, pair<int, int>>> elst(n-1);
	rep(i, n-1) {
		int ui, vi, wi;
		cin >> ui >> vi >> wi;
		--ui; --vi;
		elst[i] = { wi, { ui, vi } };
	}
	sort(all(elst));
	dsu d(n);
	ll res = 0;
	rep(i, n-1) {
		auto [ui, vi] = elst[i].second;
		int wi = elst[i].first;
		res += (ll)wi * d.size(ui) * d.size(vi);
		d.merge(ui, vi);
	}
	cout << res << endl;
	return 0;
}
