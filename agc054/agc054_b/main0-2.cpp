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

// 本番中に実装3、わからない

using mint = modint998244353;

int n;
vector<int> w;
map<pair<string, int>, mint> memo;
mint calc(string bs, int d=0, int val=0) {
	if (memo.find({ bs, val }) != memo.end()) return memo[{bs,val}];
	if (d == n) {
		if (val == 0) return (memo[{bs,val}] = 1);
		else return (memo[{bs,val}] = 0);
	}
	mint res = 0;
	bool taka = (val <= 0);
	rep(i, n) if (bs[i]=='0') {
		bs[i] = '1';
		int nval = val + (taka ? w[i] : -w[i]);
		res += calc(bs, d+1, nval);
		bs[i] = '0';
	}
	return (memo[{bs,val}] = res);
}

int main() {
	cin >> n;
	w = vector<int>(n);
	rep(i, n) cin >> w[i];
	int sum = 0;
	rep(i, n) sum += w[i];
	if (sum % 2 != 0) {
		cout << 0 << endl;
		return 0;
	}
	sum /= 2;
	vector<string> dp(n+1, string(sum+1,'0'));
	dp[0][0] = '1';
	rep(i, n) {
		dp[i+1] = dp[i];
		rep(j, sum-w[i]+1) if (dp[i][j] == '1') dp[i+1][j+w[i]] = '1';
	}
	if (dp[n][sum] != '1') {
		cout << 0 << endl;
		return 0;
	}
	set<set<int>> que;
	que.insert({sum});
	rep3r(i, 1, n+1) {
		set<set<int>> nque;
		while (!que.empty()) {
			auto p = *que.begin(); que.erase(que.begin());
			
		}
	}
	memo = map<pair<string, int>, mint>();
	auto res = calc(string(n,'0'));
	cout << res.val() << endl;
	return 0;
}
