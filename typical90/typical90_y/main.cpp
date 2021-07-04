#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
	ll n, b;
	cin >> n >> b;
	string nstr = to_string(n);
	int nlen = nstr.length();
	function<ll(string,int,string)> calc = [&](string si, int d, string ti) {
		if (d>0 && si>ti.substr(0, d)) return 0LL;
		int tl = (int)(ti.length());
		if (d == tl) {
			if (si == string(d, '0')) return 0LL;
			ll fi = 1;
			rep(i, tl) fi *= (ll)(si[i]-'0');
			if (fi+b > stoll(ti)) return 0LL;
			string si1 = si, si2 = to_string(fi+b);
			sort(all(si1));
			sort(all(si2));
			if (si1 == si2) return 1LL;
			else return 0LL;
		}
		int di = ((d == 0) ? 0 : ((char)(si.back()) - '0'));
		ll rval = 0;
		rep3(i, di, 10) rval += calc(string(si+(char)('0'+i)), d+1, ti);
		return rval;
	};
	ll res = 0;
	rep3(i, 1, nlen) res += calc("", 0, string(i, '9'));
	res += calc("", 0, nstr);
	cout << res << endl;
	return 0;
}
