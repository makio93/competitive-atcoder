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
	int q;
	cin >> q;
	deque<pair<int, int>> d;
	bool br = true;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int x, c;
			cin >> x >> c;
			d.emplace_back(x, c);
		}
		else {
			int c;
			cin >> c;
			ll res = 0;
			while (c > 0) {
				int sub = min(c, d.front().second);
				res += (ll)d.front().first * sub;
				d.front().second -= sub;
				c -= sub;
				if (d.front().second == 0) d.pop_front();
			}
			cout << res << endl;
			if (br) br = false;
		}
	}
	if (br) cout << endl;
	return 0;
}
