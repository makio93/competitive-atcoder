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

int main() {
	string s, t;
	rep(i, 3) {
		char si;
		cin >> si;
		s.push_back(si);
	}
	rep(i, 3) {
		char ti;
		cin >> ti;
		t.push_back(ti);
	}
	int cnt = 0;
	rep(i, 3) {
		if (s[i] == t[i]) continue;
		rep3(j, i+1, 3) if (s[j] == t[i]) {
			swap(s[i], s[j]);
			++cnt;
			break;
		}
	}
	if (cnt%2 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
