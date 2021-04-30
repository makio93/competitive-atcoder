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

// 自力で実装、AC

int main() {
	int n, q;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	set<int> alst;
	rep(i, n) alst.insert(a[i]);
	cin >> q;
	rep(i, q) {
		int bi;
		cin >> bi;
		auto itr = alst.upper_bound(bi);
		int res = -1;
		if (itr == alst.end()) res = abs(bi-(*prev(itr)));
		else if (itr == alst.begin()) res = abs(bi-(*itr));
		else res = min(abs(bi-(*prev(itr))), abs(bi-(*itr)));
		cout << res << endl;
	}
	return 0;
}
