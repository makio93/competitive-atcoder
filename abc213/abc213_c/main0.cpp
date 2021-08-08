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

// 自力AC

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	set<int> amemo, bmemo;
	rep(i, n) {
		amemo.insert(a[i]);
		bmemo.insert(b[i]);
	}
	map<int, int> a2, b2;
	for (int ai : amemo) a2[ai] = (int)(a2.size()) + 1;
	for (int bi : bmemo) b2[bi] = (int)(b2.size()) + 1;
	rep(i, n) cout << a2[a[i]] << ' ' << b2[b[i]] << endl;
	return 0;
}
