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

// 本番WA,1

using mint = modint998244353;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	map<int, set<int>> ab;
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		ab[ai].insert(bi);
	}
	map<set<int>, mint> slst;
	set<int> sti;
	rep(i, 2*n) sti.insert(i);
	slst[sti] = 1;
	rep(i, n) {
		map<set<int>, mint> tlst;
		for (auto& p : slst) for (auto& p2 : ab) {
			if (p.first.find(p2.first)!=p.first.end() && next(p.first.find(p2.first))!=p.first.end()) {
				if (p2.second.find(*next(p.first.find(p2.first))) != p2.second.end()) {
					auto tti = p.first;
					tti.erase(p2.first);
					tti.erase(*next(p.first.find(p2.first)));
					tlst[tti] += p.second;
				}
			}
		}
		swap(tlst, slst);
		if (slst.empty()) break;
	}
	mint res = 0;
	if (!slst.empty()) for (auto p : slst) res += p.second;
	cout << res.val() << endl;
	return 0;
}
