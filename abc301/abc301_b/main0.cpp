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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> res;
	res.push_back(a[0]);
	rep3(i, 1, n) {
		int sub = (a[i] > a[i-1]) ? 1 : -1;
		while (res.back()+sub != a[i]) {
			int nval = res.back() + sub;
			res.push_back(nval);
		}
		res.push_back(a[i]);
	}
	int m = res.size();
	rep(i, m) cout << res[i] << (i<m-1?' ':'\n');
	return 0;
}
