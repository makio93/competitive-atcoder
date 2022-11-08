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
	unordered_set<int> svals;
	vector<int> avals(n), bvals(n);
	int ma = INF, mb = INF;
	rep(i, n) {
		int ai = a[i], sval = 1;
		for (int j=2; j*j<=ai; ++j) if (ai%j == 0) {
			while (ai%j == 0) {
				ai /= j;
				if (j == 2) avals[i]++;
				else if (j == 3) bvals[i]++;
				else sval *= j;
			}
		}
		if (ai > 1) {
			if (ai == 2) avals[i]++;
			else if (ai == 3) bvals[i]++;
			else sval *= ai;
		}
		ma = min(ma, avals[i]);
		mb = min(mb, bvals[i]);
		svals.insert(sval);
	}
	if ((int)(svals.size()) > 1) {
		cout << -1 << endl;
		return 0;
	}
	int res = 0;
	rep(i, n) res += (avals[i] - ma) + (bvals[i] - mb);
	cout << res << endl;
	return 0;
}
