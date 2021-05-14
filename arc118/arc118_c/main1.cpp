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

// 解説を見てから作成、AC

int main() {
	int n;
	cin >> n;
	vector<int> seeds = { 6, 10, 15 };
	set<int> a;
	rep(i, 3) a.insert(seeds[i]);
	bool full = ((int)(a.size()) >= n);
	rep(i1, 3) {
		int val = seeds[i1] * 2;
		while (!full && val<=10000) {
			if (a.find(val) != a.end()) {
				val += seeds[i1];
				continue;
			}
			a.insert(val);
			if ((int)(a.size()) >= n) full = true;
			val += seeds[i1];
		}
		if (full) break;
	}
	vector<int> res;
	for (auto itr=a.begin(); itr!=a.end(); ++itr) res.push_back(*itr);
	rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
	return 0;
}
