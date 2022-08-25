// 自力AC

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
	int res = 0;
	rep(i, n) rep3(j, i+1, n) rep3(k, j+1, n) {
		ll sval = abs((ll)(x[j]-x[i])*(y[k]-y[i]) - (ll)(x[k]-x[i])*(y[j]-y[i]));
		if (sval>0 && sval%2==0) ++res;
	}
	cout << res << endl;
	return 0;
}
