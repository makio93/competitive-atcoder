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
	int n, m;
	cin >> n >> m;
	dsu d(n);
	vector<int> dcnt(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		d.merge(ui, vi);
		dcnt[ui]++;
		dcnt[vi]++;
	}
	unordered_map<int, int> vcnt, mcnt;
	rep(i, n) {
		vcnt[d.leader(i)]++;
		mcnt[d.leader(i)] += dcnt[i];
	}
	bool ok = true;
	for (const auto& pi : vcnt) if (mcnt[pi.first] != pi.second*2) ok = false;
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
