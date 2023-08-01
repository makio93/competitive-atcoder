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

const int INF = (int)(1.1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	int li = 0, ri = INF;
	while (ri-li > 1) {
		int ci = ri - (ri-li) / 2, acnt = 0, bcnt = 0;
		rep(i, n) if (a[i] <= ci) ++acnt;
		rep(i, m) if (b[i] >= ci) ++bcnt;
		if (acnt >= bcnt) ri = ci;
		else li = ci;
	}
	cout << ri << endl;
	return 0;
}
