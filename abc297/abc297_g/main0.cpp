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
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int gval = 0;
	rep(i, n) {
		int tval = a[i] % (l+r);
		gval ^= tval / l;
	}
	if (gval == 0) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}
