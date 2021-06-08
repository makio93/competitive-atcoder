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

// 自力AC

int main() {
	ll a;
	int b, c;
	cin >> a >> b >> c;
	ll val = 1;
	bool ok = false;
	rep(i, b) {
		if (a/c < val) {
			ok = true;
			break;
		}
		val *= c;
	}
	if (!ok && a<val) ok = true;
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
