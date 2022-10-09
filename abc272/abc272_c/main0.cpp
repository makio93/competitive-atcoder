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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int>> vals(2);
	rep(i, n) vals[a[i]%2].push_back(a[i]);
	int mval = -1;
	rep(i, 2) {
		sort(all(vals[i]), greater<int>());
		if (vals[i].size() >= 2U) mval = max(mval, vals[i][0]+vals[i][1]);
	}
	cout << mval << endl;
	return 0;
}
