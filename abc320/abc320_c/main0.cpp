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
	int m;
	cin >> m;
	vector<string> s(3);
	rep(i, 3) {
		string si;
		cin >> si;
		rep(j, 3) s[i] += si;
	}
	int res = INF;
	rep(i, 10) {
		vector<int> ord(3);
		iota(all(ord), 0);
		do {
			int id = 0, dep = 0;
			while (id<m*3 && dep<3) {
				if (s[ord[dep]][id]-'0' == i) ++dep;
				++id;
			}
			if (dep == 3) res = min(res, id-1);
		} while (next_permutation(all(ord)));
	}
	if (res == INF) res = -1;
	cout << res << endl;
	return 0;
}
