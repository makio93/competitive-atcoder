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
	vector<ll> mul(nlen+1, -1);
	vector<int> digit(nlen+1, -1);
	function<ll(int,int,bool)> dfs = [&](int d, int t, bool b) {
		if (mul[d] > k) return 0LL;
		if (d == t-1) {
			return (ll)(digit[d]+1);
		}
		ll res = 0;
		if (b) {
			digit[d+1] = nstr[d+1] - '0';
			mul[d+1] = mul[d] * digit[d+1];
			res += dfs(d+1, t, true);
			if (digit[d+1] > 0) {
				digit[d+1]--;
				mul[d+1] = mul[d] * digit[d+1];
				res += dfs(d+1, t, false);
			}
			int di = digit[d];
			digit[d+1] = 9;
			repr(i, di) {
				digit[d] = i;
				if (d > 0) mul[d] = mul[d-1] * digit[d];
				else mul[d] = digit[d];
				mul[d+1] = mul[d] * digit[d+1];
				res += dfs(d+1, t, false);
			}
		}
		else {
			int di = digit[d];
			digit[d+1] = 9;
			repr(i, di+1) {
				digit[d] = i;
				if (d > 0) mul[d] = mul[d-1] * digit[d];
				else mul[d] = digit[d];
				mul[d+1] = mul[d] * digit[d+1];
				res += dfs(d+1, t, false);
			}
		}
		return res;
	};
	ll ans = 0;
	rep3(i, 1, nlen) {
		digit[0] = 9;
		mul[0] = 9;
		ans += dfs(0, i, false);
	}
	digit[0] = nstr[0] - '0';
	mul[0] = digit[0];
	ans += dfs(0, nlen, true);
	cout << ans << endl;
	return 0;
}
