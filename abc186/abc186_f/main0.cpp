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
	int h, w, m;
	cin >> h >> w >> m;
	vector<int> ctor(w, h), rtoc(h, w);
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		ctor[yi] = min(ctor[yi], xi);
		rtoc[xi] = min(rtoc[xi], yi);
	}
	ll res = 0;
	vector<vector<int>> rlst(h+1);
	rep(i, rtoc[0]) {
		res += ctor[i];
		rlst[ctor[i]].push_back(i);
	}
	rlst[0].push_back(rtoc[0]);
	fenwick_tree<int> ft(w+1);
	rep3(i, rtoc[0], w+1) ft.add(i, 1);
	rep3(i, 1, ctor[0]) {
		res += ft.sum(0, rtoc[i]);
		for (const int& ti : rlst[i]) ft.add(ti, 1);
	}
	cout << res << endl;
	return 0;
}
