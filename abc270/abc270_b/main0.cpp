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
	int x, y, z;
	cin >> x >> y >> z;
	auto is_mid = [](int li, int ri, int ci) -> bool {
		if (li > ri) swap(li, ri);
		return (ci>=li && ci<=ri);
	};
	int res = -1;
	if (!is_mid(0, x, y)) res = abs(x);
	else if (is_mid(0, y, z)) res = abs(x);
	else {
		if (x < 0) {
			x = -x;
			y = -y;
			z = -z;
		}
		if (z < y) res = abs(z) + abs(x-z);
	}
	cout << res << endl;
	return 0;
}
