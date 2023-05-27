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
	string s, t;
	cin >> n >> s >> t;
	bool ok = true;
	rep(i, n) {
		if (s[i] == t[i]) continue;
		if (s[i] == '1' && t[i] == 'l') continue;
		if (s[i] == 'l' && t[i] == '1') continue;
		if (s[i] == '0' && t[i] == 'o') continue;
		if (s[i] == 'o' && t[i] == '0') continue;
		ok = false;
		break; 
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
