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

int main() {
	ll n, k;
	cin >> n >> k;
	string nstr = to_string(n);
	int nlen = nstr.length();
	vector<int> digit(nlen);
	function<ll(int,int)> dfs = [&](int d, int t) {
		if (d == t) {
			ll mul = 1;
			rep(i, d) mul *= digit[i];
			if (mul > k) return 0LL;
			
		}
	};
	return 0;
}
