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

// 自力で解答、よくわからない

int n;
vector<int> vcnt;
vector<ll> vsum;
vector<vector<int>> g;
ll res;
void dfs(int v, int p=-1) {
	ll sum = 0;
	int cnt = 1, bcnt = 0;
	rep(i, (int)(g[v].size())) {
		int t = g[v][i];
		if (t == p) continue;
		++bcnt;
		dfs(t, v);
		cnt += vcnt[t];
		sum += vsum[t] + vcnt[t];
	}
	vsum[v] = sum;
	vcnt[v] = cnt;
	if (bcnt > 1) res += vsum[v] * vcnt[v] * (bcnt*(bcnt-1)/2) / 4;
	else res += vsum[v];
}

int main() {
	cin >> n;
	vcnt = vector<int>(n);
	vsum = vector<ll>(n);
	g = vector<vector<int>>(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	res = 0;
	dfs(0);
	cout << res << endl;
	return 0;
}
