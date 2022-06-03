// 解説AC

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
	ll n;
	cin >> n;
	ll res = 0;
	for (ll i=2; i*i<=n; ++i) {
		if (n%i==0 && n/(i-1)==n%(i-1)) res += i-1;
		if (i == n/i) continue;
		if (n/(n/i-1) == n%(n/i-1)) res += n/i-1;
	}
	if (n-1>0 && n/(n-1)==n%(n-1)) res += n-1;
	cout << res << endl;
	return 0;
}
