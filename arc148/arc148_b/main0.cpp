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
	string s;
	cin >> n >> s;
	if (s == string(n, 'd')) {
		cout << s << endl;
		return 0;
	}
	int li = -1;
	rep(i, n) if (s[i] == 'p') {
		li = i;
		break;
	}
	string res = s;
	rep3(i, li, n) {
		string t = s;
		int tlen = i - li + 1;
		rep(j, tlen) t[li+j] = (s[i-j] == 'd') ? 'p' : 'd';
		res = min(res, t);
	}
	cout << res << endl;
	return 0;
}
