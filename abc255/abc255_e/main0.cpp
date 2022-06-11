// 本番AC

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
	cin >> n >> m;
	vector<int> s(n-1), x(m);
	rep(i, n-1) cin >> s[i];
	rep(i, m) cin >> x[i];
	vector<ll> b(n);
	rep(i, n-1) b[i+1] = s[i] - b[i];
	map<ll, int> scnt;
	rep(i, n) {
		rep(j, m) {
			ll sval = x[j] - b[i];
			if (i%2 == 1) sval = -sval;
			scnt[sval]++;
		}
	}
	int res = 0;
	for (auto pi : scnt) res = max(res, pi.second);
	cout << res << endl;
	return 0;
}
