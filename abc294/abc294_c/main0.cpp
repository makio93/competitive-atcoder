// 本番AC

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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	vector<pair<int, int>> clst(n+m);
	rep(i, n) clst[i] = { a[i], i };
	rep(i, m) clst[n+i] = { b[i], i+n };
	sort(all(clst));
	vector<int> res(n+m);
	rep(i, n+m) res[clst[i].second] = i;
	rep(i, n) cout << (res[i]+1) << (i<n-1?' ':'\n');
	rep(i, m) cout << (res[n+i]+1) << (i<m-1?' ':'\n');
	return 0;
}
