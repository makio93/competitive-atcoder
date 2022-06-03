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

const ll LINF = (ll)(1e18);

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		string nstr;
		cin >> nstr;
		int nlen = nstr.length();
		ll nval = stoll(nstr);
		ll res = stoll(string(nlen-1, '9'));
		rep3(i, 1, nlen) if (nlen%i == 0) {
			for (int j=0; j<nlen; j+=i) {
				string stamp = nstr.substr(j, i);
				string tstr;
				rep(j2, nlen/i) tstr += stamp;
				ll tval = stoll(tstr);
				if (tval <= nval) res = max(res, tval);
				else {
					string tstamp = to_string(stoll(stamp) - 1);
					reverse(all(tstamp));
					while (tstamp.length() < stamp.length()) tstamp.push_back('0');
					reverse(all(tstamp));
					string ttstr;
					rep(j2, nlen/i) ttstr += tstamp;
					ll ttval = stoll(ttstr);
					if (ttval <= nval) res = max(res, ttval);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
