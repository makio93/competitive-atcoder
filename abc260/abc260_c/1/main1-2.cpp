// 学習1回目,解説AC2

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
	auto calc = [&](auto calc, int di, bool red) -> ll {
		if (di == 1) {
			if (!red) return 1;
			else return 0;
		}
		else {
			if (!red) return calc(calc, di-1, true) + calc(calc, di-1, false) * y;
			else return calc(calc, di, false) * x + calc(calc, di-1, true);
		}
	};
	cout << calc(calc, n, true) << endl;
	return 0;
}
