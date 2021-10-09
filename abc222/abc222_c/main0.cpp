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

map<char, int> cid = { { 'G', 0 }, { 'C', 1 }, { 'P', 2 } };

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(2*n);
	rep(i, 2*n) cin >> a[i];
	vector<pair<int, int>> rank(2*n);
	rep(i, 2*n) rank[i] = { 0, -i };
	rep(i, m) {
		for (int j=0; j<2*n; j+=2) {
			int id0 = cid[a[-rank[j].second][i]], id1 = cid[a[-rank[j+1].second][i]];
			if ((id0+1)%3 == id1) rank[j].first++;
			else if ((id1+1)%3 == id0) rank[j+1].first++;
		}
		sort(rank.rbegin(), rank.rend());
	}
	rep(i, 2*n) cout << ((-rank[i].second)+1) << endl;
	return 0;
}
