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
	int n, d;
	cin >> n >> d;
	if ((ll)n*d > (ll)n*(n-1)/2) cout << "No" << endl;
	else {
		vector<pair<int, int>> res;
		rep(i, n) rep3(j, 1, d+1) res.emplace_back(i%n+1, (i+j)%n+1);
		cout << "Yes" << endl;
		int m = res.size();
		rep(i, m) cout << res[i].first << ' ' << res[i].second << endl;
	}
	return 0;
}
