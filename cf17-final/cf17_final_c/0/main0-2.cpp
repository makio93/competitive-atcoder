// バチャ終了後,自力AC

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
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	if (n > 23) {
		cout << 0 << endl;
		return 0;
	}
	int res = 0;
	set<map<int, int>> dst;
	map<int, int> st;
	st[0]++;
	dst.insert(st);
	rep(i, n) {
		set<map<int, int>> nst;
		for (auto& pi : dst) {
			if (pi.find(d[i]) == pi.end()) {
				auto tst = pi;
				tst[d[i]]++;
				nst.insert(tst);
			}
			if (d[i] == (24-d[i])%24) continue;
			if (pi.find(24-d[i]) == pi.end()) {
				auto tst = pi;
				tst[24-d[i]]++;
				nst.insert(tst);
			}
		}
		swap(nst, dst);
	}
	for (auto pi : dst) {
		vector<int> tvals;
		for (auto itr=pi.begin(); itr!=pi.end(); ++itr) tvals.push_back(itr->first);
		sort(all(tvals));
		tvals.push_back(24);
		int val = INF, m = tvals.size();
		rep(i, m-1) val = min(val, tvals[i+1]-tvals[i]);
		res = max(res, val);
	}
	cout << res << endl;
	return 0;
}
