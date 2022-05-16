// 本番WA

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

__int128_t gcd(__int128_t a, __int128_t b) { return (b ? gcd(b, a%b) : a); }
__int128_t lcm(__int128_t a, __int128_t b) { return (a / gcd(a, b) * b); }

struct fraction {
	__int128_t dy, dx;
	fraction(__int128_t dy_, __int128_t dx_) {
		dy = dy_; dx = dx_;
		if (dy == 0) dx = 1;
		else {
			if (dx < 0) {
				dy *= -1;
				dx *= -1;
			}
			__int128_t gv = gcd(abs(dy), abs(dx));
			dy /= gv; dx /= gv;
		}
	}
	bool operator<(const fraction& other) const {
		return dy * other.dx < other.dy * dx;
	}
	bool operator<=(const fraction& other) const {
		return dy * other.dx <= other.dy * dx;
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	if (k == 1) {
		cout << "Infinity" << endl;
		return 0;
	}
	vector<int> ids(n);
	iota(all(ids), 0);
	sort(all(ids), [&](int id1, int id2){
		if (x[id1] != x[id2]) return x[id1] < x[id2];
		else return y[id1] < y[id2];
	});
	map<pair<fraction, fraction>, int> cnt;
	rep(i, n) rep3(j, i+1, n) if (x[ids[i]] != x[ids[j]]) {
		ll ay = y[ids[j]] - y[ids[i]], ax = x[ids[j]] - x[ids[i]];
		fraction af(ay, ax);
		fraction tmpf(-x[ids[i]]*af.dy, af.dx);
		fraction bf(y[ids[i]]*tmpf.dx+tmpf.dy, tmpf.dx);
		cnt[{af, bf}]++;
	}
	int res = 0;
	for (auto& pi : cnt) if (pi.second >= k-1) ++res;
	unordered_map<ll, int> ycnt;
	rep(i, n) ycnt[x[i]]++;
	for (auto& pi : ycnt) if (pi.second >= k) ++res;
	cout << res << endl;
	return 0;
}
