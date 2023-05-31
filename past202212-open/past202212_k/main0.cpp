// バチャ本番WA

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
int dcnt(ll val) {
	int dval = 0;
	while (val > 0) {
		dval += val % 10;
		val /= 10;
	}
	return dval;
}

int main() {
	int a, b;
	ll x;
	cin >> a >> b >> x;
	int xlen = to_string(x).length();
	ll res = 0;
	int bval = 1;
	while ((ll)bval*b <= min(x, (ll)(xlen*9+1)*b)) {
		ll mval = 0, aval = (x - (ll)bval * b) / a;
		if (dcnt(aval) <= bval) mval = aval;
		string astr = to_string(aval);
		int alen = astr.length();
		vector<int> digit(alen, 0);
		function<ll(int,int,int)> calc = [&](int di, int vi, int bi) {
			if (vi == alen) return 0LL;
			int tval = min(9, bi);
			digit[vi] = tval;
			ll rval = calc(di, vi+1, bi-tval);
			if (rval == -1) return rval;
			if (vi > di) return rval;
			else {
				ll sval = 0;
				rep(i, alen) {
					sval *= 10;
					sval += digit[i];
				}
				return sval;
			}
		};
		int dsum = 0;
		rep(i, alen) {
			digit[i] = astr[i] - '0';
			dsum += digit[i];
			if (digit[i] == 0) continue;
			digit[i]--;
			--dsum;
			if (dsum > bval) break;
			ll cval = calc(i+1, i+1, bval-dsum);
			mval = max(mval, cval);
			if (dsum+1 <= bval) mval = max(mval, cval+1);
			digit[i]++;
			++dsum;
		}
		res = max(res, mval);
		++bval;
	}
	cout << res << endl;
	return 0;
}
