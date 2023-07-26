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
	int n, q;
	cin >> n >> q;
	vector<multiset<int>> blst(n);
	unordered_map<int, set<int>> bids;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int i, j;
			cin >> i >> j;
			--j;
			blst[j].insert(i);
			bids[i].insert(j+1);
		}
		else if (qi == 2) {
			int i;
			cin >> i;
			--i;
			for (auto itr=blst[i].begin(); itr!=blst[i].end(); ++itr) cout << (*itr) << (next(itr)!=blst[i].end()?' ':'\n');
		}
		else {
			int i;
			cin >> i;
			for (auto itr=bids[i].begin(); itr!=bids[i].end(); ++itr) cout << (*itr) << (next(itr)!=bids[i].end()?' ':'\n');
		}
	}
	return 0;
}
