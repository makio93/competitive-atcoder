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
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) {
		int kval = min(k, a[i]/x);
		a[i] -= kval * x;
		k -= kval;
		if (k == 0) break;
	}
	priority_queue<int> alst;
	rep(i, n) alst.push(a[i]);
	while (k>0 && !alst.empty()) {
		int val = alst.top(); alst.pop();
		val = max(0, val-x);
		--k;
		if (val > 0) alst.push(val);
	}
	ll res = 0;
	while (!alst.empty()) {
		res += alst.top();
		alst.pop();
	}
	cout << res << endl;
	return 0;
}
