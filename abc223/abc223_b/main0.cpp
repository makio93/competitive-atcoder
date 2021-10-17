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
	string s;
	cin >> s;
	int n = s.length();
	string lres = s, rres = s;
	rep3(i, 1, n) {
		string t = s.substr(i) + s.substr(0, i);
		lres = min(lres, t);
		rres = max(rres, t);
	}
	cout << lres << endl;
	cout << rres << endl;
	return 0;
}
