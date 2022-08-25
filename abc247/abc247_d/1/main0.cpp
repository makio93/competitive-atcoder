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

const int INF = (int)(1e9);

int main() {
	int q;
	cin >> q;
	queue<pair<int, int>> que;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int x, c;
			cin >> x >> c;
			que.emplace(x, c);
		}
		else {
			int c;
			cin >> c;
			ll res = 0;
			while (c) {
				if (que.front().second <= c) {
					res += (ll)que.front().first * que.front().second;
					c -= que.front().second;
					que.pop();
				}
				else {
					res += (ll)que.front().first * c;
					que.front().second -= c;
					c = 0;
				}
			}
			cout << res << endl;
		}
	}
	return 0;
}
