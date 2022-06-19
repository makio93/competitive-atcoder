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
	ll n, k;
	cin >> n >> k;
	string kstr = to_string(k), rstr = kstr;
	reverse(all(rstr));
	if (stoll(rstr) < k) {
		cout << 0 << endl;
		return 0;
	}
	set<ll> st;
	while (stoll(kstr) <= n) {
		st.insert(stoll(kstr));
		kstr.push_back('0');
	}
	while (stoll(rstr) <= n) {
		st.insert(stoll(rstr));
		rstr.push_back('0');
	}
	cout << (int)(st.size()) << endl;
	return 0;
}
