// 解説AC

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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		int bcnt = count(all(s), '1'), res = 0, bid = (bcnt == 0) ? -1 : s.find('1');
		bool adj = (bcnt >= 2) && (s[bid+1] == '1');
		if (bcnt%2 == 1) res = -1;
		else if (bcnt!=2 || !adj) res = bcnt / 2;
		else if (n > 4) res = bcnt / 2 + 1;
		else if (n == 4) {
			res = bcnt / 2 + 1;
			if (bid == 1) ++res;
		}
		else res = -1;
		cout << res << endl;
	}
	return 0;
}
