// 練習0,自力AC

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
	vector<int> a(n*2);
	rep(i, n) cin >> a[i];
	rep(i, n) a[i+n] = a[i];
	vector<vector<ll>> memo(2*n, vector<ll>(2*n, -1));
	auto calc = [&](auto calc, int li, int ri) -> ll {
		if (memo[li][ri] != -1) return memo[li][ri];
		ll val = 0;
		if (li <= ri) {
			if ((n-(ri-li+1))%2 == 0) val += max(a[li%n]+calc(calc,li+1,ri), a[ri%n]+calc(calc,li,ri-1));
			else {
				if (a[li%n] >= a[ri%n]) val += calc(calc, li+1, ri);
				else val += calc(calc, li, ri-1);
			}
		}
		return memo[li][ri] = val;
	};
	ll res = 0;
	rep3(i, 1, n+1) res = max(res, a[i-1]+calc(calc,i,i+n-2));
	cout << res << endl;
	return 0;
}
