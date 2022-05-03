// 学習1回目,自力AC

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

const string tar = "ACGT";

int main() {
	string s;
	cin >> s;
	int n = s.length();
	int li = n, ri = 0;
	int res = 0;
	rep(i, n) {
		if (tar.find(s[i]) != string::npos) {
			ri = i;
			if (li == n) li = i;
			res = max(res, ri-li+1);
		}
		else li = n;
	}
	cout << res << endl;
	return 0;
}
