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

int main() {
	ll x;
	cin >> x;
	auto f = [](int val) -> ll { return (ll)val*val*val*val*val; };
	rep3(a, -120, 121) rep3(b, -120, 121) if (f(a)-f(b) == x) {
		cout << a << ' ' << b << endl;
		return 0;
	}
	return 0;
}
