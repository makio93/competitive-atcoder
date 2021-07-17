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

using mint = modint1000000007;

int main() {
	int n;
	cin >> n;
	vector<int> c(n);
	rep(i, n) cin >> c[i];
	sort(all(c));
	mint res = 1;
	rep(i, n) res *= c[i] - i;
	cout << res.val() << endl;
	return 0;
}
