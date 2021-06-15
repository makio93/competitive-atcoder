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

// 自力AC

int main() {
	string nstr; int k;
	cin >> nstr >> k;
	string res = "";
	if (nstr == string("0")) res = "0";
	else {
		ll val = 0;
		rep(i, (int)(nstr.length())) {
			val *= 8;
			val += (int)(nstr[i]-'0');
		}
		rep(i, k) {
			string tstr = "";
			while (val > 0) {
				tstr += (char)((val%9==8LL) ? ('0'+5) : ('0'+val%9));
				val /= 9;
			}
			ll nval = 0;
			repr(j, (int)(tstr.length())) {
				nval *= 8;
				nval += (int)(tstr[j]-'0');
			}
			val = nval;
		}
		while (val > 0) {
			res += (char)('0'+val%8);
			val /= 8;
		}
		reverse(all(res));
	}
	cout << res << endl;
	return 0;
}
