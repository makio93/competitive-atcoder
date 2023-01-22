// 解説AC

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
const ll LINF = (ll)(1e18);

int main() {
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ri = n;
	ll res = LINF;
	rep(li, n) {
		while (ri-1>=0 && a[li]>l-a[ri-1]) --ri;
		if (ri < n) res = min(res, (ll)l*2+(ll)abs((l-a[ri])-a[li])*2);
		if (ri-1 >= 0) res = min(res, (ll)l*2+(ll)abs((l-a[ri-1])-a[li])*2);
	}
	cout << res << endl;
	return 0;
}
