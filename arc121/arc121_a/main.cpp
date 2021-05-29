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
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<pair<int, int>> xi(n), yi(n);
	rep(i, n) {
		xi[i] = { x[i], i };
		yi[i] = { y[i], i };
	}
	sort(all(xi));
	sort(all(yi));
	vector<pair<ll, pair<int, int>>> vali;
	rep(i, 2) rep(j, 2) {
		if (i >= n-j-1) continue;
		pair<int, int> ids = { xi[i].second, xi[n-j-1].second };
		if (ids.first > ids.second) swap(ids.first, ids.second);
		vali.emplace_back(llabs((ll)(xi[n-j-1].first)-(xi[i].first)), ids);
	}
	rep(i, 3) rep(j, 3) {
		pair<int, int> ids = { yi[i].second, yi[n-j-1].second };
		if (ids.first > ids.second) swap(ids.first, ids.second);
		vali.emplace_back(llabs((ll)(yi[n-j-1].first)-(yi[i].first)), ids);
	}
	sort(vali.rbegin(), vali.rend());
	ll res = -1;
	pair<int, int> mid = vali.front().second;
	rep3(i, 1, (int)(vali.size())) if (vali[i].second != mid) {
		res = vali[i].first;
		break;
	}
	cout << res << endl;
	return 0;
}
