// 学習1回目,解説AC

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
	vector<pair<int, int>> xy(n);
	rep(i, n) cin >> xy[i].first >> xy[i].second;
	sort(all(xy));
	int res = 0;
	rep(i, n) rep3(j, i+1, n) if (xy[j].first>xy[i].first && xy[j].second>xy[i].second) {
		if (binary_search(all(xy), make_pair(xy[i].first, xy[j].second)) 
			&& binary_search(all(xy), make_pair(xy[j].first, xy[i].second)))
				++res;
	}
	cout << res << endl;
	return 0;
}
