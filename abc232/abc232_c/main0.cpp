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

// 本番AC

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ab(n);
	vector<set<int>> cd(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		ab[ai].push_back(bi);
		ab[bi].push_back(ai);
	}
	rep(i, m) {
		int ci, di;
		cin >> ci >> di;
		--ci; --di;
		cd[ci].insert(di);
		cd[di].insert(ci);
	}
	vector<int> ord(n);
	rep(i, n) ord[i] = i;
	bool ok = false;
	do {
		bool same = true;
		rep(i, n) for (int vi : ab[i]) if (cd[ord[i]].find(ord[vi]) == cd[ord[i]].end()) same = false;
		if (same) {
			ok = true;
			break;
		}
	} while (next_permutation(all(ord)));
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
