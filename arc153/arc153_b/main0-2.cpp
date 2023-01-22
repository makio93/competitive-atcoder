// 自力AC

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
	int h, w, q;
	cin >> h >> w;
	vector<string> ab(h);
	rep(i, h) cin >> ab[i];
	cin >> q;
	vector<int> a(q), b(q);
	rep(i, q) cin >> a[i] >> b[i];
	int aid = 0, bid = 0;
	rep(i, q) {
		if (aid < a[i]) aid = a[i] - aid;
		else aid = h - (aid - a[i]);
		if (bid < b[i]) bid = b[i] - bid;
		else bid = w - (bid - b[i]);
	}
	vector<int> alst(h), blst(w);
	if (q%2 == 0) {
		rep(i, h) alst[(aid+i)%h] = i;
		rep(i, w) blst[(bid+i)%w] = i;
	}
	else {
		rep(i, h) alst[(aid+i)%h] = h-1-i;
		rep(i, w) blst[(bid+i)%w] = w-1-i;
	}
	vector<string> res(h, string(w, '.'));
	rep(i, h) rep(j, w) res[i][j] = ab[alst[i]][blst[j]];
	rep(i, h) cout << res[i] << endl;
	return 0;
}
