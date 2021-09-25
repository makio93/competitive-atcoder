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

// 本番終了後,自力AC

int main() {
	string n;
	cin >> n;
	int nlen = n.length();
	string sstr = string(nlen, '1'), sstr2 = sstr;
	ll sub = 0, nval = stoll(n), res = 0;
	repr(i, nlen) {
		ll sval = stoll(sstr), sval2 = stoll(sstr2);
		if (nval >= stoll(sstr)) {
			ll mval = min(sval2, nval);
			res += (ll)(i+1) * (mval-sval+1 - sub);
			sub += mval - sval + 1 - sub;
		}
		sstr[i] = '0'; sstr2[i] = '9';
	}
	rep3(i1, 1, nlen) {
		string sstri = string(i1, '1'), sstri2 = sstri, nstri = string(i1, '9');
		ll subi = 0, nvali = stoll(nstri);
		repr(i, i1) {
			ll svali = stoll(sstri), svali2 = stoll(sstri2);
			if (nvali >= stoll(sstri)) {
				ll mval = min(svali2, nvali);
				res += (ll)(i+1) * (mval-svali+1-subi);
				subi += mval-svali+1-subi;
			}
			sstri[i] = '0'; sstri2[i] = '9';
		}
	}
	cout << res << endl;
	return 0;
}
