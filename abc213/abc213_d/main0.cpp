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

vector<set<int>> g;
vector<int> ans;
void dfs(int v=0, int p=-1) {
	ans.push_back(v+1);
	for (int t : g[v]) if (t != p) {
		dfs(t, v);
		ans.push_back(v+1);
	}
}

int main() {
	int n;
	cin >> n;
	g = vector<set<int>>(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].insert(bi);
		g[bi].insert(ai);
	}
	dfs();
	int len = ans.size();
	rep(i, len) printf("%d%c", ans[i], (i<len-1)?' ':'\n');
	return 0;
}
