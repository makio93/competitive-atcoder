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

using mint = modint998244353;

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		int h = (n+1) / 2;
		string t = s;
		rep(i, h) t[n-1-i] = s[i];
		mint res = 0;
		if (t <= s) {
			res = s[h-1] - 'A' + 1;
			repr(i, h-1) {
				res += mint(s[i]-'A') * mint(26).pow(h-i-1);
			}
		}
		else {
			res = s[h-1] - 'A';
			repr(i, h-1) {
				res += mint(s[i]-'A') * mint(26).pow(h-i-1);
			}
		}
		cout << res.val() << endl;
	}
	return 0;
}
