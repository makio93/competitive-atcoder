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
	int n, k;
	cin >> n >> k;
	ll res = 0;
	rep3(i, k, n+2) {
		ll ai = (ll)(i-1) * i / 2, bi = (ll)(n+n-i+1) * i / 2;
		res = (res + bi - ai + 1) % mod;
	}
	cout << res << endl;
	return 0;
}
