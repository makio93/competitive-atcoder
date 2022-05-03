// 学習1回目,自力AC

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
	int n, m;
	cin >> n >> m;
	vector<int> s(m), p(m);
	rep(i, m) {
		int ki;
		cin >> ki;
		rep(j, ki) {
			int si;
			cin >> si;
			--si;
			s[i] |= 1<<si;
		}
	}
	rep(i, m) cin >> p[i];
	int res = 0;
	rep(i, (1<<n)) {
		bool ok = true;
		rep(j, m) if (__builtin_popcount(i&s[j])%2 != p[j]) ok = false;
		if (ok) ++res;
	}
	cout << res << endl;
	return 0;
}
