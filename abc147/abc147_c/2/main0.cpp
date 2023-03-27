// 学習2回目,バチャ本番AC

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
	vector<pair<int, int>> alst(n, { 0, 0 });
	rep(i, n) {
		int ai;
		cin >> ai;
		rep(j, ai) {
			int xi, yi;
			cin >> xi >> yi;
			--xi;
			alst[i].first |= 1 << xi;
			alst[i].second |= yi << xi;
		}
	}
	int res = 0;
	rep(i, 1<<n) {
		bool ok = true;
		rep(j, n) if ((i&(1<<j)) && (i&alst[j].first)!=alst[j].second) ok = false;
		if (ok) res = max(res, __builtin_popcount(i));
	}
	cout << res << endl;
	return 0;
}
