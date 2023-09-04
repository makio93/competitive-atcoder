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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll asum = accumulate(all(a), 0LL);
	int ltar = asum / n, mtar = asum % n;
	sort(a.rbegin(), a.rend());
	ll res = 0;
	rep(i, n) {
		int vtar = ltar + (i < mtar ? 1 : 0);
		res += max(0, a[i]-vtar);
	}
	cout << res << endl;
	return 0;
}
