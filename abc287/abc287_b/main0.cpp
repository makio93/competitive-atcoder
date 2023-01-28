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
	vector<string> s(n), t(m);
	rep(i, n) cin >> s[i];
	rep(i, m) cin >> t[i];
	int res = 0;
	rep(i, n) if ((int)(count(all(t), s[i].substr(3, 3))) > 0) ++res;
	cout << res << endl;
	return 0;
}
