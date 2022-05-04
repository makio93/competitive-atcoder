// 練習0,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	int d, n, m;
	cin >> d >> n >> m;
	vector<int> di(n*2), ki(m);
	di[0] = 0, di[n] = d;
	rep3(i, 1, n) {
		cin >> di[i];
		di[i+n] = di[i] + d;
	}
	sort(all(di));
	rep(i, m) cin >> ki[i];
	ll res = 0;
	rep(i, m) {
		auto itr = upper_bound(all(di), ki[i]);
		res += min(abs(*itr-ki[i]), abs(*prev(itr)-ki[i]));
	}
	cout << res << endl;
	return 0;
}
