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
	string from = "01689", to = "01986";
	string s, res;
	cin >> s;
	repr(i, (int)(s.length())) rep(j, 5) if (s[i] == from[j]) {
		res += to[j];
		break;
	}
	cout << res << endl;
	return 0;
}
