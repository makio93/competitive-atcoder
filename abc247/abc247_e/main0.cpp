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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	stack<pair<int, int>> stx, stn;
	ll res = 0;
	int xl = n, xr = -1, nl = n, nr = -1;
	rep(i, n) {
		int tmp = 1;
		while (!stx.empty() && stx.top().first<=a[i]) {
			tmp += stx.top().second;
			stx.pop();
		}
		stx.emplace(a[i], tmp);
		if (a[i] > x) xl = n, xr = -1;
		else if (a[i] == x) xl = i-stx.top().second+1, xr = i;
		tmp = 1;
		while (!stn.empty() && stn.top().first>=a[i]) {
			tmp += stn.top().second;
			stn.pop();
		}
		stn.emplace(a[i], tmp);
		if (a[i] < y) nl = n, nr = -1;
		else if (a[i] == y) nl = i-stn.top().second+1, nr = i;
		res += max(0, min(xr,nr)-max(xl,nl)+1);
	}
	cout << res << endl;
	return 0;
}
