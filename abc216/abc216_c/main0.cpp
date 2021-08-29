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

// 本番AC

int main() {
	ll n;
	cin >> n;
	string res;
	while (n > 0LL) {
		if (n%2 == 1) {
			res += 'A';
			--n;
		}
		else {
			res += 'B';
			n /= 2;
		}
	}
	reverse(all(res));
	cout << res << endl;
	return 0;
}
