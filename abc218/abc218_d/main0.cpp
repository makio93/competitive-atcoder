#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	map<int, set<int>> xlst;
	rep(i, n) xlst[x[i]].insert(y[i]);
	map<pair<int, int>, ll> pcnt;
	for (auto xl : xlst) {
		for (auto litr=xl.second.begin(); litr!=xl.second.end(); ++litr) {
			for (auto ritr=next(litr); ritr!=xl.second.end(); ++ritr) pcnt[{*litr,*ritr}]++;
		}
	}
	ll res = 0;
	for (auto p : pcnt) res += p.second * (p.second-1) / 2;
	cout << res << endl;
	return 0;
}
