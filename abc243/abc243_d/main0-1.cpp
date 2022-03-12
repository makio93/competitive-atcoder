// 本番1WA

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
	int n;
	ll x;
	cin >> n >> x;
	string s;
	cin >> s;
	__int128_t tmpx = x;
	rep(i, n) {
		if (s[i] == 'U') tmpx /= 2;
		else if (s[i] == 'L') tmpx *= 2;
		else if (s[i] == 'R') tmpx = tmpx * 2 + 1;
	}
	ll ans = tmpx;
	cout << ans << endl;
	return 0;
}
