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
	int a, b;
	cin >> a >> b;
	bool along = true;
	if (a < b) along = false;
	vector<int> res;
	if (along) {
		rep3(ai, 1, a+1) res.push_back(ai);
		rep3(bi, 1, b) res.push_back(-bi);
		int lsub = (a*(a+1) / 2) - (b*(b+1) / 2);
		res.push_back(-(b+lsub));
	}
	else {
		rep3(bi, 1, b+1) res.push_back(-bi);
		rep3(ai, 1, a) res.push_back(ai);
		int lsub = (b*(b+1)/2) - (a*(a+1)/2);
		res.push_back(a+lsub);
	}
	int n = res.size();
	rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
	return 0;
}
