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
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> csum(n+1);
	rep(i, n) {
		int cnt = (a[i] == i) ? 1 : 0;
		csum[i+1] = csum[i] + cnt;
	}
	ll res = 0;
	rep(i, n) {
		if (a[i] == i) res += csum[i];
		else if (a[i] < i) {
			if (a[a[i]] == i) ++res;
		}
	}
	cout << res << endl;
	return 0;
}
