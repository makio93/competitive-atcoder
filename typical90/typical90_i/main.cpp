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

// 自力AC

const double PI = acos(-1);

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<pair<int, int>> xy(n);
	rep(i, n) xy[i] = { x[i], y[i] };
	sort(all(xy));
	map<int, map<double, int>> dlst;
	double res = 0.0;
	repr(i, n-1) {
		rep3(j, i+1, n) {
			double d = 90.0;
			if (xy[j].first != xy[i].first) d = atan((xy[j].second-xy[i].second)/(double)(xy[j].first-xy[i].first))*180.0/PI;
			if (!dlst[j].empty()) {
				auto itr = dlst[j].lower_bound(d);
				double sub = (itr != dlst[j].end()) ? (180.0 - fabs((itr->first)-d)) : 0.0;
				if (itr != dlst[j].begin()) sub = max(sub, (180.0-fabs((prev(itr)->first)-d)));
				res = max(res, sub);
			}
			dlst[i][d]++;
		}
	}
	printf("%.14f\n", res);
	return 0;
}
