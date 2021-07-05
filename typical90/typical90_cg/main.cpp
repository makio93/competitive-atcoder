#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	ll k;
	cin >> k;
	ll res = 0;
	for (ll a=1; a*a*a<=k; ++a) if (k%a == 0LL) {
		for (ll b=a; a*b*b<=k; ++b) if (k%(a*b) == 0LL) ++res;
	}
	cout << res << endl;
	return 0;
}
