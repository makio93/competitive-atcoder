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
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	rep(i, n) cin >> l[i] >> r[i];
	int mval = 0;
	rep(i, n) mval = max({ mval, l[i], r[i] });
	vector<int> sub(mval+1);
	rep(i, n) {
		sub[l[i]]++;
		sub[r[i]]--;
	}
	rep(i, mval) sub[i+1] += sub[i];
	rep(i, mval+1) sub[i] = min(sub[i], 1);
	vector<pair<int, int>> res;
	pair<int, int> nval = { -1, -1 };
	rep(i, mval) {
		if (sub[i]==0 && sub[i+1]==1) nval.first = i+1;
		else if (sub[i]==1 && sub[i+1]==0) {
			nval.second = i+1;
			res.push_back(nval);
			nval = { -1, -1 };
		}
	}
	int k = res.size();
	rep(i, k) cout << res[i].first << ' ' << res[i].second << endl;
	return 0;
}
