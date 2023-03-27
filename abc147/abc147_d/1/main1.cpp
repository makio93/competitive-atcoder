// 学習1回目,解説AC

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
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<int> bcnt(60);
	rep(i, n) rep(j, 60) bcnt[j] += (a[i] >> j) & 1;
	ll res = 0;
	rep(i, 60) res = (res + (ll)bcnt[i] * (n-bcnt[i]) % mod * ((1LL<<i) % mod)) % mod;
	cout << res << endl;
	return 0;
}
