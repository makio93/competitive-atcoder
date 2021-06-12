#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll asum = 0;
	rep(i, n) asum += a[i];
	sort(all(a));
	double cent = (n%2==1) ? a[n/2] : (a[n/2]+a[n/2-1]) / 2.0;
	double x = cent / 2.0;
	ll msum = 0;
	rep(i, n) msum += min(2*a[i], (ll)(2*cent));
	double res = (double)((double)asum + x * n - msum / 2.0) / (double)n;
	printf("%.14f\n", res);
	return 0;
}
