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

const string word = "oxx";

int main() {
	string s;
	cin >> s;
	int n = s.length();
	string tar = "";
	int wcnt = (n+2) / 3 + 1;
	rep(i, wcnt) tar += word;
	bool ok = false;
	rep(i, 3) if (tar.substr(i, n) == s) ok = true;
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
