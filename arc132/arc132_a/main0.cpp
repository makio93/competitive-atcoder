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
	int n, q;
	cin >> n;
	vector<int> r(n), c(n);
	rep(i, n) cin >> r[i];
	rep(i, n) cin >> c[i];
	cin >> q;
	string res;
	rep(i, q) {
		int ri, ci;
		cin >> ri >> ci;
		--ri; --ci;
		if (c[ci] <= n-r[ri]) res += '.';
		else res += '#';
	}
	cout << res << endl;
	return 0;
}
