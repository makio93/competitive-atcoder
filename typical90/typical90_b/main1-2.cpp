// 解説と実装を見てから実装

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
	int n;
	cin >> n;
	if (n%2 != 0) {
		cout << endl;
		return 0;
	}
	rep(i, (1<<n)) {
		string str;
		repr(j, n) str += ((i&(1<<j)) == 0) ? '(' : ')';
		bool ok = true;
		int scnt = 0;
		rep(j, n) {
			scnt += (str[j] == '(') ? 1 : -1;
			if (scnt < 0) ok = false;
		}
		if (scnt != 0) ok = false;
		if (ok) cout << str << endl;
	}
	return 0;
}
