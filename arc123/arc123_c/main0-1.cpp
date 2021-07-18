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

// 本番中2、WA

ll calc(string& s, int d=0, bool high=false, ll val=0) {
	int di = s[d] - '0';
	if ((int)(s.length()) == d) return val;
	if (!high) {
		if (di == 0) return -1;
		else if (di>=1 && di<=3) {
			ll res = calc(s, d+1, false, val*10+di);
			if (res != -1) return res;
			else if (d==0 || di>1) {
				res = calc(s, d+1, true, val*10+di-1);
				if (res != -1) return res;
			}
			else return -1;
		}
		else {
			ll res = calc(s, d+1, true, val*10+3);
			if (res != -1) return res;
			else return -1;
		}
	}
	else {
		ll res = calc(s, d+1, true, val*10+3);
		if (res != -1) return res;
		else return -1;
	}
}

int main() {
	int t;
	cin >> t;
	rep(i, t) {
		ll n;
		cin >> n;
		int cnt = 0;
		while (n > 0) {
			string s = to_string(n);
			ll val = calc(s);
			n -= val;
			++cnt;
		}
		cnt = min(cnt, 4);
		cout << cnt << endl;
	}
	return 0;
}
