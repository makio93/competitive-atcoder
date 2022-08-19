// 自力,TLE

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

using mint = modint1000000007;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), s(n+1);
	rep(i, n) cin >> a[i];
	rep(i, n) s[i+1] = s[i] + a[i];
	map<tuple<int, int, int, int>, mint> memo;
	function<mint(int,int,int,int)> calc = [&](int l, int r, int bl, int br) {
		if (memo.find(make_tuple(l,r,bl,br)) != memo.end()) return memo[make_tuple(l,r,bl,br)];
		if (br<=bl || r<=l) return (memo[make_tuple(l,r,bl,br)] = (mint)0);
		if (br-bl > r-l) return (memo[make_tuple(l,r,bl,br)] = (mint)0);
		if (br-bl == 1) {
			if ((s[r]-s[l])%bl == 0LL) return (memo[make_tuple(l,r,bl,br)] = (mint)1);
			else return (memo[make_tuple(l,r,bl,br)] = (mint)0);
		}
		else {
			mint res = 0;
			rep3(i, l+1, r-(br-bl-1)+1) if ((s[i]-s[l])%bl == 0LL) res += calc(i, r, bl+1, br);
			return (memo[make_tuple(l,r,bl,br)] = res);
		}
	};
	mint ans = 0;
	rep3(i, 2, n+2) ans += calc(0, n, 1, i);
	cout << ans.val() << endl;
	return 0;
}
