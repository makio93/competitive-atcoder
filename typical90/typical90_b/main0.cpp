// 自力で実装、AC

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

void dfs(vector<string>& res, int n, string tstr="", int d=0, int p=0) {
	if (d == n) res.push_back(tstr);
	else {
		if (p < n/2) dfs(res, n, tstr+'(', d+1, p+1);
		if (d-p < p) dfs(res, n, tstr+')', d+1, p);
	}
}

int main() {
	int n;
	cin >> n;
	if (n%2 != 0) cout << endl;
	else {
		vector<string> res;
		dfs(res, n);
		int len = res.size();
		rep(i, len) cout << res[i] << endl;
	}
	return 0;
}

