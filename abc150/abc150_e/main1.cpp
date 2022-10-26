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

const ll mod = (ll)(1e9) + 7;

int main() {
	int n;
	cin >> n;
	vector<int> c(n);
	rep(i, n) cin >> c[i];
	sort(all(c), greater<int>());
	ll res = 0;
	rep(i, n) res += (ll)c[i] * (i+2) % mod;
	rep(i, n-1) res = res * 4 % mod;
	cout << res << endl;
	return 0;
}
