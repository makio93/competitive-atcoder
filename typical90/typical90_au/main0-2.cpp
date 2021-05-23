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

// 高速化しようとしてみた、TLE

int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	const string tar = "RGB";
	vector<int> sval(n), tval(n);
	rep(i, n) rep(j, 3) if (s[i] == tar[j]) sval[i] = j;
	rep(i, n) rep(j, 3) if (t[i] == tar[j]) tval[i] = j;
	int res = 0;
	for (int l=n-1; l>=-n+1; --l) {
		int r = l + n, l2 = max(l, 0), r2 = min(r, n);
		bool ok = true;
		int mval = (sval[l2]+tval[l2-l]) % 3;
		rep3(i, l2+1, r2) {
			if ((sval[i]+tval[i-l])%3 != mval) {
				ok = false;
				break;
			}
		}
		if (ok) ++res;
	}
	cout << res << endl;
	return 0;
}
