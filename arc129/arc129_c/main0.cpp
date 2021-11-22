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

// 本番WA1

int main() {
	int n;
	cin >> n;
	string s;
	while (n > 0) {
		int len = 1;
		while ((ll)(len+1)*(len+2)/2 <= (ll)n) ++len;
		s += string(len, '7');
		n -= (int)((ll)(len)*(len+1)/2);
		if (n > 0) {
			int tval = (6 - len % 6) % 6, r = 1;
			rep(i, tval) r = r * 3 % 7;
			s += (char)(r+'0');
		}
	}
	reverse(all(s));
	cout << s << endl;
	return 0;
}
