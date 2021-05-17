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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> snum(n), tnum(n);
	int scnt = 0, tcnt = 0;
	rep(i, n) if (s[i] == '0') {
		++scnt;
		snum[i] = scnt;
	}
	rep(i, n) if (t[i] == '0') {
		++tcnt;
		tnum[i] = tcnt;
	}
	if (scnt != tcnt) cout << -1 << endl;
	else {
		int res = 0;
		rep(i, n) if (snum[i] != 0) {
			if (snum[i] != tnum[i]) ++res;
		}
		cout << res << endl;
	}
	return 0;
}
