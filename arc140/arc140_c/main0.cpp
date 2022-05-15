// 本番,WA

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
	int n, x;
	cin >> n >> x;
	vector<int> p;
	p.push_back(x);
	set<int> lst;
	rep3(i, 1, n+1) if (i != x) lst.insert(i);
	int len = 1;
	rep(i, n-1) {
		int nval = p.back() + len, pval = p.back() - len;
		if (lst.lower_bound(nval) != lst.end()) {
			int val = *lst.lower_bound(nval);
			p.push_back(val);
			++len;
			lst.erase(val);
		}
		else if (lst.upper_bound(pval) != lst.begin()) {
			int val = *prev(lst.upper_bound(pval));
			p.push_back(val);
			++len;
			lst.erase(val);
		}
		else {
			int val = *lst.begin();
			p.push_back(val);
			lst.erase(val);
		}
	}
	rep(i, n) printf("%d%c", p[i], (i<n-1?' ':'\n'));
	return 0;
}
