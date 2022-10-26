// 学習1,自力AC

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
	vector<int> p(n), q(n);
	rep(i, n) cin >> p[i];
	rep(i, n) cin >> q[i];
	if (p > q) swap(p, q);
	int res = 0;
	while (p != q) {
		next_permutation(all(p));
		++res;
	}
	cout << res << endl;
	return 0;
}
