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
	map<int, int> s;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int xi;
			cin >> xi;
			s[xi]++;
		}
		else if (qi == 2) {
			int xi, ci;
			cin >> xi >> ci;
			if (s.find(xi) != s.end()) {
				s[xi] -= min(ci, s[xi]);
				if (s[xi] == 0) s.erase(xi);
			}
		}
		else {
			int ai = s.begin()->first, bi = s.rbegin()->first;
			cout << (bi - ai) << endl;
		}
	}
	return 0;
}
