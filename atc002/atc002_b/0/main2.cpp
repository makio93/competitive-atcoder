// 解説AC,別解

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
	ll n, m, p;
	cin >> n >> m >> p;
	ll res = 1;
	while (p) {
		if (p%2) res = res * n % m;
		n = n * n % m;
		p >>= 1;
	}
	cout << res << endl;
	return 0;
}
