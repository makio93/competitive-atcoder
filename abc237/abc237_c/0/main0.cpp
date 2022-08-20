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
	string s;
	cin >> s;
	int n = s.length();
	int lcnt = 0, rcnt = 0;
	rep(i, n) {
		if (s[i] != 'a') break;
		else ++lcnt;
	}
	repr(i, n) {
		if (s[i] != 'a') break;
		else ++rcnt;
	}
	if (lcnt > rcnt) {
		cout << "No" << endl;
		return 0;
	}
	reverse(all(s));
	s += string(rcnt-lcnt, 'a');
	bool par = true;
	int m = s.length();
	for (int i=0; i<m/2; ++i) if (s[i] != s[m-1-i]) {
		par = false;
		break;
	}
	if (par) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
