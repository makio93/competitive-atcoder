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
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}
	unordered_map<int, unordered_set<int>> abids;
	rep(i, n) {
		abids[a[i]].insert(i);
		abids[b[i]].insert(i);
	}
	vector<int> nids(n, -1);
	multiset<int> sids;
	vector<ll> res(m+2);
	rep(i, m) {
		if (abids.find(i) != abids.end()) {
			for (int qi : abids[i]) {
				if (nids[qi] != -1) sids.erase(sids.find(nids[qi]));
				nids[qi] = i;
				sids.insert(i);
			}
		}
		if ((int)(sids.size()) == n) {
			int di = i - *sids.begin() + 1;
			res[di]++;
			res[i+2]--;
		}
	}
	rep(i, m+1) res[i+1] += res[i];
	rep3(i, 1, m+1) cout << res[i] << (i<m?' ':'\n');
	return 0;
}
