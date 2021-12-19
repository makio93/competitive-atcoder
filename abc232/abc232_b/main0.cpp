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

// 本番AC

int main() {
	string s, t;
	cin >> s >> t;
	int slen = (26 - (s[0] - 'a')) % 26, tlen = (26 - (t[0] - 'a')) % 26;
	for (char& ci : s) ci = (char)('a' + ((ci-'a') + slen) % 26);
	for (char& ci : t) ci = (char)('a' + ((ci-'a') + tlen) % 26);
	if (s == t) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
