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
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	vector<pair<int, int>> res;
	vector<int> ids0, ids1;
	rep(i, n) {
		if (i%2==0 && p[i]%2==1) ids0.push_back(i);
		else if (i%2==1 && p[i]%2==0) ids1.push_back(i);
	}
	int m = ids0.size();
	rep(i, m) {
		int li = ids0[i], ri = ids1[i];
		if (li > ri) swap(li, ri);
		while (ri-li > 1) {
			ri -= 2;
			res.emplace_back(2, ri+1);
			swap(p[ri], p[ri+2]);
		}
		res.emplace_back(1, ri);
		swap(p[ri-1], p[ri]);
	}
	rep(i, n) if (p[i] != i) {
		int tid = find(all(p), i) - p.begin();
		while (tid-i > 1) {
			tid -= 2;
			res.emplace_back(2, tid+1);
			swap(p[tid], p[tid+2]);
		}
	}
	int s = res.size();
	cout << s << endl;
	rep(i, s) {
		if (res[i].first == 1) cout << 'A';
		else cout << 'B';
		cout << ' ' << res[i].second << endl;
	}
	return 0;
}
