// 自力AC

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
	ll a, x, m;
	cin >> a >> x >> m;
	if (a == 1) {
		cout << (x%m) << endl;
		return 0;
	}
	int len = 0;
	while (x > 1LL<<len) ++len;
	vector<ll> ap(len+1), xlst(len+1);
	ap[0] = a % m;
	rep(i, len) ap[i+1] = ap[i] * ap[i] % m;
	xlst[0] = 1;
	rep(i, len) xlst[i+1] = (xlst[i] * ap[i] % m + xlst[i]) % m;
	ll res = 0;
	rep(i, len+1) if (x&(1LL<<i)) res = (res * ap[i] % m + xlst[i]) % m;
	cout << res << endl;
	return 0;
}
