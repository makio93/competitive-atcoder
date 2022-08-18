// 自力WA

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
	int t;
	cin >> t;
	rep(i1, t) {
		int n;
		cin >> n;
		deque<int> p(n);
		rep(i, n) cin >> p[i];
		vector<int> a;
		set<pair<int, deque<int>::iterator>> tar;
		rep(i, n) tar.emplace(p[i], &p[i]);
		rep(i, n) {
			if (distance(tar.begin()->second, p.begin()) == tar.begin()->first-1) {
				tar.erase(tar.begin());
				continue;
			}
			int pval = -1, d = -1;
			for (auto itr=tar.begin(); itr!=tar.end(); ++itr) {
				if (distance(itr->second, p.begin())-1 == i) {
					pval = itr->first;
					d = distance(itr->second, p.begin()) - 1;
					tar.erase(itr);
					break;
				}
			}
			if (pval == -1) break;
			rep3r(j, i+1, d+2) a.push_back(j);
			int l = i;
			while (l-1>=0 && p[l-1]>pval) {
				a.push_back(l);
				--l;
			}
			p.erase(p.begin()+d);
			p.insert(p.begin()+l, pval);
		}
		int ai = a.size();
		cout << ai << endl;
		rep(i, ai) printf("%d%c", a[i], (i<ai-1?' ':'\n'));
	}
	return 0;
}
