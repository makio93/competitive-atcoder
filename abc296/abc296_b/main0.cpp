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
	vector<string> s(8);
	rep(i, 8) cin >> s[i];
	int xi = -1, yi = -1;
	rep(i, 8) rep(j, 8) if (s[7-i][j] == '*') xi = i, yi = j;
	string res = string("") + (char)('a'+yi) + (char)('1'+xi);
	cout << res << endl;
	return 0;
}
