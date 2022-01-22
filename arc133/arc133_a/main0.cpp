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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> b;
	b.push_back(a[0]);
	rep3(i, 1, n) if (a[i] != a[i-1]) b.push_back(a[i]);
	int x = b[0], len = b.size();
	rep3(i, 1, len) {
		if (b[i] > b[i-1]) x = b[i];
		else break;
	}
	vector<int> res;
	rep(i, n) if (a[i] != x) res.push_back(a[i]);
	int rlen = res.size();
	if (rlen > 0) rep(i, rlen) printf("%d%c", res[i], (i<rlen-1?' ':'\n'));
	else cout << endl;
	return 0;
}
