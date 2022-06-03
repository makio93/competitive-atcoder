// 自力AC

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
	string s;
	cin >> s;
	int n = s.length();
	bool ok = s[0] == 'A';
	if (ok) {
		int ccnt = 0;
		rep3(i, 2, n-1) if (s[i] == 'C') ++ccnt;
		if (ccnt != 1) ok = false;
	}
	if (ok) {
		int lcnt = 0;
		rep(i, n) if (islower(s[i])) ++lcnt;
		if (lcnt != n-2) ok = false;
	}
	if (ok) cout << "AC" << endl;
	else cout << "WA" << endl;
	return 0;
}
