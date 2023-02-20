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
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int>> aids(n);
	rep(i, n) aids[a[i]].push_back(i);
	ll res = 0;
	rep3(i, 1, n+1) res += (ll)(n+1-i) * (i / 2);
	rep(i, n) {
		int li = 0, ri = aids[i].size() - 1;
		while (ri > li) {
			if (aids[i][li] <= (n-1)-aids[i][ri]) {
				res -= (ll)(ri-li) * (aids[i][li]+1);
				++li;
			}
			else {
				res -= (ll)(ri-li) * (n-aids[i][ri]);
				--ri;
			}
		}
	}
	cout << res << endl;
	return 0;
}
