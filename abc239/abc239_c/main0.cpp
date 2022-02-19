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

int main() {
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	bool res = false;
	for (ll dx1=-5; dx1<=5; ++dx1) for (ll dy1=-5; dy1<=5; ++dy1) {
		ll nx1 = x1 + dx1, ny1 = y1 + dy1;
		for (ll dx2=-5; dx2<=5; ++dx2) for (ll dy2=-5; dy2<=5; ++dy2) {
			ll nx2 = x2 + dx2, ny2 = y2 + dy2;
			if (nx1==nx2 && ny1==ny2 && dx1*dx1+dy1*dy1==5 && dx2*dx2+dy2*dy2==5) {
				res = true;
				break;
			}
		}
		if (res) break;
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
