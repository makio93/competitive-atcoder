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
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length(), rlen = 0;
	rep(i, m) {
		if (s[n-1-i]=='?' || t[m-1-i]=='?' || s[n-1-i]==t[m-1-i]) ++rlen;
		else break;
	}
	if (rlen == m) cout << "Yes" << endl;
	else cout << "No" << endl;
	bool match = true;
	rep(i, m) {
		bool res = true;
		if (match) {
			if (s[i]=='?' || t[i]=='?' || s[i]==t[i]) { if (rlen < m-1-i) res = false; }
			else match = res = false;
		}
		else res = false;
		if (res) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
