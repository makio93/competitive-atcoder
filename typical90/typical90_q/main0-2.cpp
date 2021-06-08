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

// 自力AC、ACLあり

int main() {
	int n, m;
	cin >> n >> m;
	map<int, vector<int>> rl;
	rep(i, m) {
		int li, ri;
		cin >> li >> ri;
		--li; --ri;
		rl[ri].push_back(li);
	}
	ll res = 0;
	fenwick_tree<ll> fw(n);
	for (auto itr=rl.rbegin(); itr!=rl.rend(); ++itr) {
		int ri = itr->first; auto la = itr->second;
		rep(i, (int)(la.size())) res += fw.sum(la[i]+1, ri);
		rep(i, (int)(la.size())) fw.add(la[i], 1);
	}
	cout << res << endl;
	return 0;
}
