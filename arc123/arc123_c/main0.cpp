#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中、WA

int main() {
	int t;
	cin >> t;
	rep(i0, t) {
		ll n;
		cin >> n;
		string s = to_string(n);
		int len = s.length();
		vector<ll> digit(len);
		rep(i, len) digit[i] = s[i] - '0';
		bool ok = false;
		while (!ok) {
			ok = true;
			rep(i, len-1) {
				ll l1 = (digit[i] + 2) / 3;
				while (digit[i+1] < l1) {
					digit[i]--;
					digit[i+1] += 10;
					l1 = (digit[i] + 2) / 3;
					if (ok) ok = false;
				}
			}
		}
		ll res = 0;
		rep(i, len) res = max(res, (ll)(digit[i]+2)/3);
		cout << res << endl;
	}
	return 0;
}
