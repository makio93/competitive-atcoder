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
	vector<pair<int, int>> xy2(n);
	rep(i, n) cin >> xy2[i].first >> xy2[i].second;
    sort(all(xy2));
	int rx = 0, ry = 0;
	rep(i, n) {
		int dx = xy2[i].first - x1[0], dy = xy2[i].second - y1[0];
		bool ok = true;
		rep(j, m) {
            auto itr = lower_bound(all(xy2), make_pair(x1[j]+dx, y1[j]+dy));
            if (itr==xy2.end() || *itr!=make_pair(x1[j]+dx,y1[j]+dy)) {
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
