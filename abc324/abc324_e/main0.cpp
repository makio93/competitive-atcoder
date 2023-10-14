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
	int n;
	string t;
	cin >> n >> t;
	int m = t.length();
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<int> vcnt(m+1);
	rep(i, n) {
		int id = 0;
		for (const char& ci : s[i]) if (t[id] == ci) {
			++id;
			if (id >= m) break;
		}
		vcnt[id]++;
	}
	repr(i, m) vcnt[i] += vcnt[i+1];
	ll res = 0;
	rep(i, n) {
		int id = m-1, slen = s[i].length();
		repr(j, slen) if (t[id] == s[i][j]) {
			--id;
			if (id < 0) break;
		}
		int ri = m - id - 1;
		res += vcnt[m-ri];
	}
	cout << res << endl;
	return 0;
}
