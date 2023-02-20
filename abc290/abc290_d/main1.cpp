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

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, d, k;
		cin >> n >> d >> k;
		int s = n / gcd(n, d);
		cout << ((ll)(k-1) * d % n + (k-1) / s) << endl;
	}
	return 0;
}
