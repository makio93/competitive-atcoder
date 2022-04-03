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

const ll mod = 998244353LL;
using mint = modint998244353;

vector<mint> dfs(ll n, vector<mint> a){
	vector<mint> d = { 1, 1 };
	int k = 2;
	if(n == 2LL)  return d;
	vector<mint> res(k);
	if(n&1 || n<k*2){
		vector<mint> x = dfs(n-1, a);
		for(int i = 0; i < k; ++i)  res[i] = d[i] * x[k - 1];
		for(int i = 0; i + 1 < k; ++i)  res[i + 1] += x[i];
	}
	else{
		vector<vector<mint>> x(k, vector<mint>(k));
		x[0] = dfs(n>>1, a);
		for(int i = 0; i + 1 < k; ++i){
			for(int j = 0; j < k; ++j)  x[i + 1][j] = d[j] * x[i][k - 1];
			for(int j = 0; j + 1 < k; ++j)  x[i + 1][j + 1] += x[i][j];
		}
		for(int i = 0; i < k; ++i){
			for(int j = 0; j < k; ++j){
				res[j] += x[0][i] * x[i][j];
			}
		}
	}
	return res;
}

int main() {
	ll n; int k;
	cin >> n >> k;
	assert(k == 1);
	vector<mint> a(2, 1), x = dfs(n+1, a);
	mint res = 0;
	for(int i = 0; i < 2; ++i)  res += x[i] * a[i];
	cout << res.val() << endl;
	return 0;
}
