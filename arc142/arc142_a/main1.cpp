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

const int INF = (int)(1e9);

ll f(ll x) {
	string rx = to_string(x);
	reverse(all(rx));
	return min(x, stoll(rx));
}

int main() {
	ll n, k;
	cin >> n >> k;
	if (f(k) != k) {
		cout << 0 << endl;
		return 0;
	}
	string kstr = to_string(k), rstr = kstr;
	reverse(all(rstr));
	ll rk = stoll(rstr);
	set<ll> st;
	while (k <= n) {
		st.insert(k);
		k *= 10;
	}
	while (rk <= n) {
		st.insert(rk);
		rk *= 10;
	}
	cout << (int)(st.size()) << endl;
	return 0;
}
