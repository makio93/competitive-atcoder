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
	int n, x, y;
	cin >> n >> x >> y;
	ll red = 1, blue = 0;
	rep3r(i, 2, n+1) {
		ll nred = red, nblue = 0;
		blue += red * x;
		nred += blue;
		nblue += blue * y;
		swap(red, nred);
		swap(blue, nblue);
	}
	cout << blue << endl;
	return 0;
}
