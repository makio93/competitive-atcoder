// 解説AC

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
	ll p, q, r;
	cin >> n >> p >> q >> r;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> asum(n+1);
	rep(i, n) asum[i+1] += asum[i] + a[i];
	set<ll> ast;
	bool res = false;
	rep(i, n+1) ast.insert(asum[i]);
	for (const ll& aval : ast) {
		ll val1 = aval + p, val2 = val1 + q, val3 = val2 + r;
		if (ast.find(val1)!=ast.end() && ast.find(val2)!=ast.end() && ast.find(val3)!=ast.end()) {
			res = true;
			break;
		}
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
