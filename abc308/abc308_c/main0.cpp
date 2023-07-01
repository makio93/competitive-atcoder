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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool {
		int ln = a[li], ld = a[li] + b[li], rn = a[ri], rd = a[ri] + b[ri];
		return make_pair(ln*(ll)rd, -li) > make_pair(rn*(ll)ld, -ri);
	});
	rep(i, n) cout << (ord[i]+1) << (i<n-1?' ':'\n');
	return 0;
}
