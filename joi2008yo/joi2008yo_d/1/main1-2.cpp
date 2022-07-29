// 

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
	int m, n;
	cin >> m;
	vector<int> x1(m), y1(m);
	rep(i, m) cin >> x1[i] >> y1[i];
	cin >> n;
	vector<int> x2(n), y2(n);
	rep(i, n) cin >> x2[i] >> y2[i];
	int xmval = INF;
	unordered_set<ll> pst;
	rep(i, n) pst.insert((ll)y2[i]*xmval+x2[i]);
	int rx = 0, ry = 0;
	rep(i, n) {
		int dx = x2[i] - x1[0], dy = y2[i] - y1[0];
		bool ok = true;
		rep(j, m) {
            if (pst.find((ll)(y1[j]+dy)*xmval+(x1[j]+dx)) == pst.end()) {
                ok = false;
                break;
            }
		}
		if (ok) {
			rx = dx;
			ry = dy;
			break;
		}
	}
	cout << rx << ' ' << ry << endl;
	return 0;
}
