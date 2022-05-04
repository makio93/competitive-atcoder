// 学習2,自力AC

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

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> p;
	p.push_back(0);
	rep(i, n) {
		int pi;
		cin >> pi;
		p.push_back(pi);
	}
	vector<int> s;
	int plen = p.size();
	rep(i, plen) rep(j, plen) s.push_back(p[i]+p[j]);
	sort(all(s));
	int res = 0;
	rep(i, plen) rep(j, plen) if (p[i]+p[j] <= m) {
		res = max(res, p[i]+p[j]+*(upper_bound(all(s), m-p[i]-p[j])-1));
	}
	cout << res << endl;
	return 0;
}
