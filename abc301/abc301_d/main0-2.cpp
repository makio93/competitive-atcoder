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

const int INF = (int)(1e9);

int main() {
	string s;
	ll n;
	cin >> s >> n;
	ll val = 0;
	int slen = s.length();
	rep(i, slen) if (s[i] == '1') val |= (1LL<<(slen-1-i));
	if (val > n) {
		cout << -1 << endl;
		return 0;
	}
	rep(i, slen) if (s[i] == '?') {
		if ((val|(1LL<<(slen-1-i))) <= n) val |= (1LL<<(slen-1-i));
	}
	cout << val << endl;
	return 0;
}
