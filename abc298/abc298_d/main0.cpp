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

using mint = modint998244353;

int main() {
	int q;
	cin >> q;
	deque<char> s(1, '1');
	mint mval = 1;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			char x;
			cin >> x;
			mval = mval * 10 + (x-'0');
			s.push_back(x);
		}
		else if (qi == 2) {
			mval -= mint(10).pow((int)(s.size())-1) * (s.front()-'0');
			s.pop_front();
		}
		else {
			cout << mval.val() << endl;
		}
	}
	return 0;
}
