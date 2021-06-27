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

// 本番中に実装2、わからない

using mint = modint998244353;

int n;
vector<int> w;
map<string, mint> memo;
mint calc(string bs, int d=0, int val=0) {
	if (memo.find(bs) != memo.end()) return memo[bs];
	if (d == n) {
		if (val == 0) return (memo[bs] = 1);
		else return (memo[bs] = 0);
	}
	mint res = 0;
	bool taka = (val <= 0);
	rep(i, n) if (bs[i]=='0') {
		bs[i] = '1';
		int nval = val + (taka ? w[i] : -w[i]);
		res += calc(bs, d+1, nval);
		bs[i] = '0';
	}
	return (memo[bs] = res);
}

int main() {
	cin >> n;
	w = vector<int>(n);
	rep(i, n) cin >> w[i];
	memo = map<string, mint>();
	auto res = calc(string(n,'0'));
	cout << res.val() << endl;
	return 0;
}
