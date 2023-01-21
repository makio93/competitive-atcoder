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
	int n, p, q, r, s;
	cin >> n >> p >> q >> r >> s;
	--p; --r;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, q-p) swap(a[p+i], a[r+i]);
	rep(i, n) cout << a[i] << (i<n-1?' ':'\n');
	return 0;
}
