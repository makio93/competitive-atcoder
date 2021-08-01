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

// 本番TLE1,遷移できないリストを持つ形でグラフを持つ方針

const ll mod = 998244353LL;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<unordered_set<int>> rg(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		rg[ui].insert(vi);
		rg[vi].insert(ui);
	}
	vector<vector<ll>> dcnt(k+1, vector<ll>(n));
	dcnt[0][0] = 1;
	rep(i, k) rep(j, n) rep(j2, n) {
		if (j!=j2 && rg[j].find(j2)==rg[j].end()) dcnt[i+1][j2] = (dcnt[i+1][j2] + dcnt[i][j]) % mod;
	}
	cout << dcnt[k][0] << endl;
	return 0;
}
