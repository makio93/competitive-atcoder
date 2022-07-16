// 

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
	int n, k;
	cin >> n >> k;
	if (k*2 > n) {
		cout << -1 << endl;
		return 0;
	}
	int rlen = n / (k*2);
	vector<int> res(n);
	rep(i, rlen-1) {
		int si = i * (k*2);
		rep(j, k) {
			res[si+j] = si + j + k + 1;
			res[si+j+k] = si + j + 1;
		}
	}
	int rval = n % (k*2);
	int lsi = (rlen-1) * (k*2);
	rep(j, k) {
		res[lsi+j] = lsi + j + k + 1;
		res[lsi+j+k+rval] = lsi + j + 1;
	}
	rep(j, rval) {
		res[lsi+k+j] = lsi + k + j + k + 1;
	}
	rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	return 0;
}
