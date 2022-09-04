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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	multiset<int> alst;
	rep(i, n) alst.insert(a[i]);
	int res = 0;
	while ((int)(alst.size()) > 1) {
		int lval = *alst.begin(), rval = *prev(alst.end());
		alst.erase(alst.begin());
		alst.erase(prev(alst.end()));
		rval %= lval;
		alst.insert(lval);
		if (rval > 0) alst.insert(rval);
		++res;
	}
	cout << res << endl;
	return 0;
}
