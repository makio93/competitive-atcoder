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
	int n, h, x;
	cin >> n >> h >> x;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	int res = 0;
	rep(i, n) if (h+p[i] >= x) {
		res = i + 1;
		break;
	}
	cout << res << endl;
	return 0;
}
