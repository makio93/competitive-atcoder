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

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		string s;
		ll l, r;
		cin >> s >> l >> r;
		auto numb = [](string s, ll id, int b) -> ll {
			int slen = s.length(), r = b-slen;
			if (r < 0) return -1;
			id--;
			ll add = 1, sadd = 1;
			rep(i, r) add *= 10;
			rep(i, b) sadd *= 10;
			if (s[0] == '0') id += add;
			return id / add * sadd + stoll(s) * add + id % add;
		};
		auto ccnt = [&numb](string s, ll r) -> ll {
			ll res = 0;
			rep3(i, 1, 17) {
				ll aval = numb(s, 1, i);
				if (aval==-1 || aval>r) continue;
				ll lval = 1, rval = 1;
				rep(ii, 16-s.length()) rval *= 10;
				++rval;
				while (rval-lval > 1) {
					ll cval = lval + (rval-lval) / 2, nval = numb(s, cval, i);
					if (nval <= r) lval = cval;
					else rval = cval;
				}
				res += lval;
			}
			return res;
		};
		ll res = ccnt(s, r) - ccnt(s, l-1);
		cout << res << endl;
	}
	return 0;
}
