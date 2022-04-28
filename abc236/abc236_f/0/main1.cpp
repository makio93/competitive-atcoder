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

// 解説AC

using bset = bitset<0x10000>;

int main() {
	int n;
	cin >> n;
	vector<int> c(1<<n);
	rep3(i, 1, (1<<n)) cin >> c[i];
	vector<pair<int, int>> clst;
	rep3(i, 1, (1<<n)) clst.emplace_back(c[i], i);
	sort(all(clst));
	bset bcnt(1);
	ll res = 0;
	rep(i, (1<<n)-1) if (!bcnt[clst[i].second]) {
		res += clst[i].first;
		rep(j, (1<<n)) if (bcnt[j]) bcnt[j^clst[i].second] = 1;
	}
	cout << res << endl;
	return 0;
}
