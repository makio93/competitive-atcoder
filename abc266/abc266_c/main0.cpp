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
	vector<int> x(4), y(4);
	rep(i, 4) cin >> x[i] >> y[i];
	bool ok = true;
	rep(i, 4) {
		int lid = i, cid = (i+1) % 4, rid = (i+2) % 4;
		int ax = x[cid] - x[lid], ay = y[cid] - y[lid], bx = x[rid] - x[cid], by = y[rid] - y[cid];
		if (ax*by-ay*bx <= 0) ok = false;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
