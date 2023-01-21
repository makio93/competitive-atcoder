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
const ll LINF = (ll)(1e18);

int main() {
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	s += s;
	ll res = LINF;
	rep(i, n) {
		ll val = (ll)a * i;
		rep(li, n/2) {
			int ri = n - li - 1;
			if (s[i+li] != s[i+ri]) val += b;
		}
		res = min(res, val);
	}
	cout << res << endl;
	return 0;
}
