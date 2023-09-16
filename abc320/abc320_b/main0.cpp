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
	string s;
	cin >> s;
	int n = s.length();
	function<bool(int, int)> is_palind = [&](int li, int ri) {
		while (ri > li) {
			if (s[li] != s[ri]) return false;
			++li; --ri;
		}
		return true;
	};
	int res = 1;
	rep(i, n) rep3(j, i+1, n) if (is_palind(i, j)) res = max(res, j-i+1);
	cout << res << endl;
	return 0;
}
