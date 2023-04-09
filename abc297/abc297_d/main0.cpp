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
	ll a, b;
	cin >> a >> b;
	ll res = 0;
	while (a != b) {
		if (a > b) swap(a, b);
		if (b%a == 0) {
			res += b / a - 1;
			b = a;
		}
		else {
			res += b / a;
			b %= a;
		}
	}
	cout << res << endl;
	return 0;
}
