// バチャ本番AC

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
	int n, m;
	cin >> n;
	vector<int> t(n);
	rep(i, n) cin >> t[i];
	cin >> m;
	vector<int> p(m), x(m);
	rep(i, m) {
		cin >> p[i] >> x[i];
		p[i]--;
	}
	ll tsum = accumulate(all(t), 0LL);
	rep(i, m) {
		int sub = x[i] - t[p[i]];
		cout << (tsum+sub) << endl;
	}
	return 0;
}
