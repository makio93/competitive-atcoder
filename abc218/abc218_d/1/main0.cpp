// バチャ本番AC

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
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	map<pair<int, int>, int> ycnt;
	rep(i, n) rep3(j, i+1, n) if (x[i]!=x[j] && y[i]==y[j]) {
		int li = x[i], ri = x[j];
		if (li > ri) swap(li, ri);
		ycnt[{li, ri}]++;
	}
	ll res = 0;
	for (const auto& pi : ycnt) res += (ll)pi.second * (pi.second-1) / 2;
	cout << res << endl;
	return 0;
}
