// 復習1,自力AC

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

int main() {
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<int> ord(n);
	iota(all(ord), 0);
	double res = 0.0;
	do {
		rep(i, n-1) res += sqrt((x[ord[i]]-x[ord[i+1]])*(x[ord[i]]-x[ord[i+1]])+(y[ord[i]]-y[ord[i+1]])*(y[ord[i]]-y[ord[i+1]]));
	} while (next_permutation(all(ord)));
	rep3(i, 1, n+1) res /= i;
	printf("%.10f\n", res);
	return 0;
}
