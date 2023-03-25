// 自力AC

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
		auto ccnt = [](string s, ll r) -> ll {
			string sr = to_string(r);
			int rlen = sr.length(), slen = s.length();
			ll rval = 0;
			for (int i=0; i+slen-1<rlen; ++i) {
				string a = sr.substr(0, i), b = sr.substr(i+slen);
				if (stoll(sr.substr(i, slen)) != stoll(s)) {
					if (stoll(sr.substr(i, slen)) < stoll(s)) {
						if (a.empty() || stoll(a)<=0) continue;
						a = to_string(stoll(a) - 1);
					}
					b = string(b.length(), '9');
				}
				if (s[0] == '0') {
					if (a.empty() || stoll(a)<=0) continue;
					a = to_string(stoll(a) - 1);
				}
				if ((a+b).empty()) rval += 1;
				else rval += stoll(a+b) + 1;
			}
			return rval;
		};
		ll res = ccnt(s, r) - ccnt(s, l-1);
		cout << res << endl;
	}
	return 0;
}
