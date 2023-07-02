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

const int INF = (int)(2.1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> alst;
	rep3(i, 2, n) alst.push_back(a[i]);
	sort(all(alst));
	int res = INF;
	for (int li=0; li+m-1<n-2; ++li) {
		int ri = li + m - 1, lval = alst[li], rval = alst[ri];
		res = min(res, max(0, a[0]-lval) + max(0, rval-a[1]));
	}
	cout << res << endl;
	return 0;
}
