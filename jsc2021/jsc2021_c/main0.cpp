// 本番AC

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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	int a, b;
	cin >> a >> b;
	ll ans = 0;
	if (a > b/2) {
		int len = b - a + 1;
		rep3r(i, 1, len+1) {
			int a2 = (a+(i-1)) / i * i;
			if (a2+i <= b) {
				ans = i;
				break;
			}
		}
	}
	else ans = b/2;
	cout << ans << endl;
	return 0;
}

