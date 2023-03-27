// 学習1回目,バチャ本番AC

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
	ll res = 0;
	repr(i, n-1) rep(j, 60) {
		if (a[i+1]&(1LL<<j)) bcnt[j]++;
		if (a[i]&(1LL<<j)) res = (res + (n-1-i-bcnt[j]) * ((1LL<<j) % mod)) % mod;
		else res = (res + bcnt[j] * ((1LL<<j) % mod)) % mod;
	}
	cout << res << endl;
	return 0;
}
