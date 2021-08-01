#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(2e9) + 5;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	sort(all(b));
	int res = INF;
	rep(i, n) {
		int id = upper_bound(all(b), a[i]) - b.begin();
		if (id < m) res = min(res, abs(a[i]-b[id]));
		if (id-1 >= 0) res = min(res, abs(a[i]-b[id-1]));
	}
	cout << res << endl;
	return 0;
}
