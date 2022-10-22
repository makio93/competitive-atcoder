// 解説AC

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

struct fraction {
	ll num, den;
	fraction(ll num=0, ll den=1) : num(num), den(den) {}
	bool operator<(const fraction& other) const {
		return num * other.den < other.num * den;
	}
	bool operator<=(const fraction& other) const {
		return num * other.den <= other.num * den;
	}
};

int main() {
	int n, a;
	cin >> n >> a;
	vector<int> w(n), x(n), v(n);
	rep(i, n) cin >> w[i] >> x[i] >> v[i];
	int res = 0;
	rep(i, n) {
		vector<pair<fraction, int>> events;
		rep(j, n) {
			int xsub = x[j] - x[i], vsub = v[j] - v[i];
			if (vsub == 0) {
				if (xsub>=0 && xsub<=a) events.emplace_back(fraction(0, 1), -w[j]);
			}
			else if (vsub > 0) {
				events.emplace_back(fraction(-xsub, vsub), -w[j]);
				events.emplace_back(fraction(a-xsub, vsub), w[j]);
			}
			else {
				events.emplace_back(fraction(xsub-a, -vsub), -w[j]);
				events.emplace_back(fraction(xsub, -vsub), w[j]);
			}
		}
		sort(all(events));
		int wval = 0;
		for (const auto& pi : events) {
			wval -= pi.second;
			if (!(pi.first < fraction(0, 1))) res = max(res, wval);
		}
	}
	cout << res << endl;
	return 0;
}
