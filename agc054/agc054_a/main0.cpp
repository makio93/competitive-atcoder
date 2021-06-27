#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中に実装

int main() {
	int n;
	string s;
	cin >> n >> s;
	char cl = s.front(), cr = s.back();
	if (cl != cr) cout << 1 << endl;
	else {
		bool ok = false;
		rep3r(i, 2, n-1) {
			if (s[i-1]!=cl && s[i]!=cr) {
				ok = true;
				break;
			}
		}
		if (ok) cout << 2 << endl;
		else cout << -1 << endl;
	}
	return 0;
}
