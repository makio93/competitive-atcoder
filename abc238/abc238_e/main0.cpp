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
	cin >> n >> q;
	dsu d(n+1);
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li;
		d.merge(li, ri);
	}
	if (d.same(0, n)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
