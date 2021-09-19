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

// 解説AC

const ll mod = 998244353LL;

int main() {
	ll n;
	cin >> n;
	ll res = 0;
	for (ll p=1; p*p<=n; ++p) res = (res + (n/p-p)/2 + 1) % mod;
	cout << res << endl;
	return 0;
}
