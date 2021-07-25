#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<unordered_map<int, set<int>>> aval(n);
	rep(i, n) rep(j, n) aval[i][a[i]^b[j]].insert(j);
	set<int> rst;
	rep(i, n) {
		int x = a[0] ^ b[i];
		bool ok = true;
		unordered_set<int> rest;
		rep(j, n) if (i != j) rest.insert(j);
		rep3(j, 1, n) {
			if (aval[j].find(x) == aval[j].end()) {
				ok = false;
				break;
			}
			else {
				bool ok2 = false;
				for (int bid : aval[j][x]) if (rest.find(bid) != rest.end()) {
					rest.erase(bid);
					ok2 = true;
					break;
				}
				if (!ok2) {
					ok = false;
					break;
				}
			}
		}
		if (ok) rst.insert(x);
	}
	vector<int> res;
	for (int ri : rst) res.push_back(ri);
	int k = res.size();
	cout << k << endl;
	rep(i, k) cout << res[i] << endl;
	return 0;
}
