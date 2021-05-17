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

// 本番中に作成、未完成

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> rcnt(n);
	vector<vector<int>> tar(n);
	rep(i, n) tar[i].push_back(i);
	rep(i, n) {
		if (i-1 >= 0) {
			bool ok = (a[i] == a[i-1]);
			if (ok) {
				rcnt[i]++;
				if (i-2 >= 0) {
					rcnt[i] += rcnt[i-2];
					for (int t : tar[i-2]) tar[i].push_back(t);
				}
			}
		}
		if (i-2 >= 0) {
			for (int t : tar[i-2]) {
				if (a[i-1]-a[i] == a[t]) {
					rcnt[i]++;
					rcnt[i] += rcnt[t];
				}
			}
		}
	}
	ll res = 0;
	rep(i, n) res += rcnt[i];
	cout << res << endl;
	return 0;
}
