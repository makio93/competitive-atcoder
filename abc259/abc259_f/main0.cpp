// 本番WA

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
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	vector<int> u(n-1), v(n-1), w(n-1);
	rep(i, n-1) {
		cin >> u[i] >> v[i] >> w[i];
		u[i]--; v[i]--;
	}
	vector<int> ord(n-1);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool {
		return (w[li] != w[ri]) ? w[li] > w[ri] : min(d[u[li]], d[v[li]]) > min(d[u[ri]], d[v[ri]]);
	});
	ll res = 0;
	rep(i, n-1) {
		if (w[ord[i]] < 0) break;
		if (d[u[ord[i]]]>0 && d[v[ord[i]]]>0) {
			res += w[ord[i]];
			d[u[ord[i]]]--;
			d[v[ord[i]]]--;
		}
	}
	cout << res << endl;
	return 0;
}
