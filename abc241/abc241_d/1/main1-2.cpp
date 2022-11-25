// 学習1,解説AC2

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
	int q;
	cin >> q;
	vector<int> qi(q), ki(q, -1);
	vector<ll> xi(q);
	rep(i, q) {
		cin >> qi[i] >> xi[i];
		if (qi[i] != 1) cin >> ki[i];
	}
	vector<ll> txi = xi;
	sort(all(txi));
	txi.erase(unique(all(txi)), txi.end());
	rep(i, q) xi[i] = lower_bound(all(txi), xi[i]) - txi.begin();
	int m = txi.size();
	fenwick_tree<int> ft(m);
	rep(i, q) {
		if (qi[i] == 1) ft.add((int)(xi[i]), 1);
		else if (qi[i] == 2) {
			if (ft.sum(0, (int)(xi[i])+1) < ki[i]) {
				cout << -1 << endl;
				continue;
			}
			int li = 0, ri = (int)xi[i] + 1;
			while (ri-li > 1) {
				int ci = li + (ri-li) / 2;
				int val = ft.sum(ci, (int)(xi[i])+1);
				if (val >= ki[i]) li = ci;
				else ri = ci;
			}
			cout << txi[li] << endl;
		}
		else {
			if (ft.sum((int)(xi[i]), m) < ki[i]) {
				cout << -1 << endl;
				continue;
			}
			int li = (int)(xi[i]) - 1, ri = m-1;
			while (ri-li > 1) {
				int ci = ri - (ri-li) / 2;
				int val = ft.sum((int)(xi[i]), ci+1);
				if (val >= ki[i]) ri = ci;
				else li = ci;
			}
			cout << txi[ri] << endl;
		}
	}
	return 0;
}
