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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll a, s;
		cin >> a >> s;
		if (s-a*2 < 0LL) {
			cout << "No" << endl;
			continue;
		}
		if ((a&(s-a*2)) == 0LL) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
