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

const ll mod = 998244353LL;
using mint = modint998244353;

vector<mint> fib(ll n){
	vector<mint> d = { 1, 1 };
	int k = 2;
	if(n == 2LL)  return d;
	vector<mint> res(k);
	if(n&1 || n<k*2){
		vector<mint> x = fib(n-1);
		for(int i=0; i<k; ++i)  res[i] = d[i] * x[k-1];
		for(int i=0; i+1<k; ++i)  res[i+1] += x[i];
	}
	else{
		vector<vector<mint>> x(k, vector<mint>(k));
		x[0] = fib(n>>1);
		for(int i=0; i+1<k; ++i){
			for(int j=0; j<k; ++j)  x[i+1][j] = d[j] * x[i][k-1];
			for(int j=0; j+1<k; ++j)  x[i+1][j+1] += x[i][j];
		}
		for(int i=0; i<k; ++i){
			for(int j=0; j<k; ++j){
				res[j] += x[0][i] * x[i][j];
			}
		}
	}
	return res;
}

int main() {
	ll n; int k;
	cin >> n >> k;
	assert(k <= 6);
	if (k == 1) {
		vector<mint> x = fib(n+1);
		mint res = 0;
		for(int i = 0; i < 2; ++i)  res += x[i];
		cout << res.val() << endl;
		return 0;
	}
	assert(n <= 6);
	ll mval = 1;
	mint res = 0;
	rep(i, n) mval *= 7;
	for (ll i=0; i<mval; ++i) {
		vector<int> arr(n);
		ll ti = i;
		rep(j, n) {
			arr[j] = ti % 7;
			ti /= 7;
		}
		bool ok = true;
		rep3(i0, 1, n+1) {
			for (int l=0; l+i0<=n; ++l) {
				int r = l + i0;
				int mi = (int)(1e9);
				rep3(i2, l, r) mi = min(mi, arr[i2]);
				if (mi*i0 > k) {
					ok = false;
					break;
				}
			}
			if (!ok) break;
		}
		if (ok) ++res;
	}
	cout << res.val() << endl;
	return 0;
}
