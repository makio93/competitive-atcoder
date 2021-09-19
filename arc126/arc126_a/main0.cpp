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

// 本番AC

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll n2, n3, n4;
		cin >> n2 >> n3 >> n4;
		ll val1 = min(n3/2, n4);
		ll cnt = val1;
		n3 -= val1 * 2; n4 -= val1;
		ll val2 = min(n2, n4/2);
		cnt += val2;
		n2 -= val2; n4 -= val2 * 2;
		ll val3 = min(n2/2, n3/2);
		cnt += val3;
		n2 -= val3 * 2; n3 -= val3 * 2;
		ll val4 = min(n2/3, n4);
		cnt += val4;
		n2 -= val4 * 3; n4 -= val4;
		ll val5 = n2 / 5;
		cnt += val5;
		n2 -= val5 * 5;
		cout << cnt << endl;
	}
	return 0;
}
