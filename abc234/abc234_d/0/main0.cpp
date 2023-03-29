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

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	set<int> vals;
	rep(i, k) vals.insert(p[i]);
	auto sitr = vals.begin();
	cout << (*sitr) << endl;
	rep3(i, k, n) {
		bool up = (p[i] > *sitr);
		vals.insert(p[i]);
		if (up) ++sitr;
		cout << (*sitr) << endl;
	}
	return 0;
}
