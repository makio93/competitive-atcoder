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

// 自力AC

const int INF = (int)(1e9);
int n;
vector<vector<int>> g;
vector<int> pdist, vcnt;
ll res;
void dfs(int v=0, int p=-1, int d=0) {
	pdist[v] = d;
	int cnt = 1;
	for (int t : g[v]) if (t != p) {
		dfs(t, v, d+1);
		cnt += vcnt[t];
	}
	vcnt[v] = cnt;
}

void dfs2(ll vsum, int v=0, int p=-1) {
	res += vsum;
	for (int t : g[v]) if (t != p) {
		ll nsum = vsum + (n-vcnt[t]) - vcnt[t];
		dfs2(nsum, t, v);
	}
}

int main() {
	cin >> n;
	g = vector<vector<int>>(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	pdist = vector<int>(n, INF); vcnt = vector<int>(n);
	dfs();
	ll psum = 0;
	rep(i, n) psum += pdist[i];
	res = 0;
	dfs2(psum);
	res /= 2;
	cout << res << endl;
	return 0;
}
