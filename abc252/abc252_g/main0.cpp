// 終了後,自力,解答不能

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
const ll mod = 998244353LL;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	fenwick_tree<int> f(n+1);
	vector<ll> sum1(n+1), sum2(n);
	repr(i, n) {
		sum1[i] = f.sum(0, p[i]);
		f.add(p[i], 1);
	}
	repr(i, n) if (sum1[i] > 0) sum1[i] = (sum1[i] + sum1[i+1]) % mod;
	repr(i, n) if (sum1[i] > 0) sum1[i] = (sum1[i] + sum1[i+1]) % mod;
	sum2[n-2] = sum1[n-2];
	repr(i, n-2) sum2[i] = sum1[i] * sum2[i+1] % mod;
	ll res = 0;
	rep(i, n-1) res = (res + sum2[i]) % mod;
	cout << res << endl;
	return 0;
}
