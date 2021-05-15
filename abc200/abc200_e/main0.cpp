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

// 本番中に作成、途中までで終了

int main() {
	ll n, k;
	cin >> n >> k;
	ll v1 = 3, s1 = 0;
	while (v1 <= n*3) {
		ll sum = min(n, v1-1) * (n, v1-2) / 2;
		if (s1+sum >= k) break;
		++v1;
		s1 += sum;
	}
	k -= s1;
	ll v2 = 1, s2 = 0;
	while (v2 <= n) {
		ll sum = (v1-v2) - 1;
		if (s2+sum >= k) break;
		++v2;
		s2 += sum;
	}
	k -= s2;
	cout << v2 << ' ' << (k) << ' ' << (v1-v2-k) << endl;
	return 0;
}
