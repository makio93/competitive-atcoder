// 解説AC

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
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> ls(n), rs(n);
	ls[a[0]]++;
	rep3(i, 2, n) rs[a[i]]++;
	ll res = 0, val = 0;
	rep(i, n) val += ls[i] * (ll)rs[i];
	rep3(i, 1, n-1) {
		res += val - ls[a[i]] * (ll)rs[a[i]];
		val -= ls[a[i]] * (ll)rs[a[i]];
		if (a[i+1] != a[i]) val -= ls[a[i+1]] * (ll)rs[a[i+1]];
		ls[a[i]]++;
		rs[a[i+1]]--;
		val += ls[a[i]] * (ll)rs[a[i]];
		if (a[i+1] != a[i]) val += ls[a[i+1]] * (ll)rs[a[i+1]];
	}
	cout << res << endl;
	return 0;
}
