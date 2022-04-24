// 

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
	int n;
	cin >> n;
	vector<int> t(n);
	rep(i, n) cin >> t[i];
	ll res = 0;
	rep(i, n) {
		if ((res>>t[i])&1LL) {
			ll tmp = res >> (t[i]+1);
			ll tmp2 = ((1LL<<61)-1) << t[i];
			res &= (1LL<<(t[i]+1)) - 1;
			res |= (tmp+1) << (t[i]+1);
			res &= tmp2;
		}
		else {
			ll tmp = ((1LL<<61)-1) << (t[i]+1);
			res &= tmp;
			res |= (1LL<<t[i]);
		}
	}
	cout << res << endl;
	return 0;
}
