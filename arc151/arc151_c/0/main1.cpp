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
	ll n;
	int m;
	cin >> n >> m;
	vector<ll> x(m);
	vector<int> y(m);
	rep(i, m) cin >> x[i] >> y[i];
	ll gval = 0;
	if (m == 0) gval = n % 2;
	else {
		gval ^= x[0] - 1;
		gval ^= n - x[m-1];
		rep(i, m-1) gval ^= (y[i] == y[i+1]) ? 1 : 0;
	}
	if (gval != 0) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
	return 0;
}
