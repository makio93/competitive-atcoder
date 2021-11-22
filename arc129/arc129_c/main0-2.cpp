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

// 本番WA2

int main() {
	int n;
	cin >> n;
	vector<int> lens;
	int sub = 0;
	bool sig = false;
	for (int i=1; i*i<=n*2; ++i) if (i*(i+1)/2 == n) {
		sig = true;
		lens.push_back(i);
		break;
	}
	if (!sig) {
		tuple<int, int, int> mval = { (int)(1e9), -1, -1 };
		for (int i=1; i*i<=n*2; ++i) {
			int lval = i*(i+1)/2, rval = n - lval;
			if (rval <= 0) continue;
			int i2 = (int)round(sqrt(rval*2));
			while (i2*(i2+1)/2 <= rval) ++i2;
			while (i2*(i2+1)/2 > rval) --i2;
			mval = min(mval, { rval-i2*(i2+1)/2, i, i2 });
		}
		lens.push_back(get<1>(mval));
		lens.push_back(get<2>(mval));
		if (get<0>(mval) > 0) sub = get<0>(mval);
	}
	string s;
	if (lens.size() == 1) {
		s += string(lens[0], '7');
	}
	else {
		s += string(lens[0], '7');
		int tval = (6 - lens[0] % 6) % 6, r = 1;
		rep(i, tval) r = r * 3 % 7;
		s += (char)(r+'0');
		s += string(lens[1], '7');
	}
	int ecnt = 2;
	if (sub > 0) {
		int tval = (6 - lens[1] % 6) % 6, r = 1;
		if (ecnt%2 == 0) r = 3;
		rep(i, tval) r = r * 3 % 7;
		s += (char)(r+'0');
		while (sub > 0) {
			int len = 1;
			while ((ll)(len+1)*(len+2)/2 <= (ll)sub) ++len;
			s += string(len, '7');
			sub -= (int)((ll)(len)*(len+1)/2);
			if (sub > 0) {
				++ecnt;
				int tval = (6 - len % 6) % 6, r = 1;
				if (ecnt%2 == 0) r = 3;
				rep(i, tval) r = r * 3 % 7;
				s += (char)(r+'0');
			}
		}
	}
	reverse(all(s));
	cout << s << endl;
	return 0;
}
