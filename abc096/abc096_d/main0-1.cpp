// 自力WA1

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
const int mval = 55555 * 5;

int main() {
	int n;
	cin >> n;
	set<int> plst;
	vector<bool> vmemo(mval+1);
	for (int i=2; i<=mval; ++i) if (!vmemo[i]) {
		plst.insert(i);
		for (int j=i*2; j<=mval; j+=i) vmemo[j] = true;
	}
	vector<int> res;
	vector<unordered_set<int>> svals(4);
	for (int pval : plst) {
		bool ok = true;
		for (int tval : svals[3]) if (plst.find(tval+pval) != plst.end()) {
			ok = false;
			break;
		}
		if (ok) {
			res.push_back(pval);
			if ((int)(res.size()) == n) break;
			repr(i, 3) for (int tval : svals[i]) svals[i+1].insert(tval+pval);
			svals[0].insert(pval);
		}
	}
	rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	return 0;
}
