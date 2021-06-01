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

int n, p, q;
vector<int> a;
ll dfs(ll val, int v=0, int d=0) {
	if (d == 5) return ((val%p==q) ? 1 : 0);
	if (v == n) return 0;
	ll nval = (d==0) ? (a[v]%p) : (val*a[v]%p);
	return dfs(val, v+1, d) + dfs(nval, v+1, d+1);
}

int main() {
	cin >> n >> p >> q;
	a = vector<int>(n);
	rep(i, n) cin >> a[i];
	ll cnt = dfs(0);
	cout << cnt << endl;
	return 0;
}
