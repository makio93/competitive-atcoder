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

const int INF = (int)(1e9);

int main() {
	string s;
	cin >> s;
	int n = s.length(), ri = n, li = -1;
	while (ri-1>=0 && s[ri-1]=='a') --ri;
	while (li+1<ri && s[li+1]=='a') ++li;
	if (li+1 > n-ri) {
		cout << "No" << endl;
		return 0;
	}
	bool ok = true;
	while (li+1 < ri-1) {
		if (s[li+1] != s[ri-1]) {
			ok = false;
			break;
		}
		++li; --ri;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
