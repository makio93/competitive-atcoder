// 本番WA

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

int main() {
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	rep(i, n) {
		int ti;
		cin >> ti >> l[i] >> r[i];
		if (ti == 2) r[i]--;
		else if (ti == 3) l[i]++;
		else if (ti == 4) { l[i]++; r[i]--; }
	}
	vector<pair<int, int>> rl(n);
	rep(i, n) rl[i] = { r[i], l[i] };
	sort(all(rl));
	rep(i, n) { r[i] = rl[i].first; l[i] = rl[i].second; }
	set<int> ri;
	ll res = 0;
	rep(i, n) {
		res += (int)(ri.size()) - distance(ri.begin(), ri.lower_bound(l[i]));
		ri.insert(r[i]);
	}
	cout << res << endl;
	return 0;
}
