// 自力WA2

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
	for (auto sitr=plst.begin(); sitr!=plst.end(); ++sitr) {
		vector<unordered_set<int>> svals(4);
		for (auto itr=sitr; *itr<=55555; ++itr) {
			bool ok = true;
			int pval = *itr;
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
		if ((int)(res.size()) == n) break;
	}
	rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	return 0;
}
