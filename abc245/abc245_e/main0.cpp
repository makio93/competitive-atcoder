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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m), d(m);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, m) cin >> c[i];
	rep(i, m) cin >> d[i];
	vector<tuple<int, int, int>> lst;
	rep(i, n) lst.emplace_back(a[i], b[i], 1);
	rep(i, m) lst.emplace_back(c[i], d[i], 2);
	sort(all(lst));
	multiset<int> ab;
	int len = lst.size();
	rep(i, len) {
		if (get<2>(lst[i]) == 1) ab.insert(get<1>(lst[i]));
		else {
			if (ab.empty()) continue;
			auto itr = ab.upper_bound(get<1>(lst[i]));
			if (itr != ab.begin()) ab.erase(prev(itr)); 
		}
	}
	if (ab.empty()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
