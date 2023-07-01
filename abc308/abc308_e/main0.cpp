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
	string s;
	cin >> s;
	vector<int> mcnt(3), xcnt(3);
	rep3r(i, 1, n) if (s[i] == 'X') xcnt[a[i]]++;
	ll res = 0;
	rep(i, n) {
		if (s[i] == 'E') {
			rep(li, 3) rep(ri, 3) {
				unordered_set<int> tst;
				tst.insert(a[i]);
				tst.insert(li);
				tst.insert(ri);
				rep(i2, 4) if (tst.find(i2) == tst.end()) {
					res += mcnt[li] * (ll)xcnt[ri] * i2;
					break;
				}
			}
		}
		if (i+1 < n) {
			if (s[i] == 'M') mcnt[a[i]]++;
			if (s[i+1] == 'X') xcnt[a[i+1]]--;
		}
	}
	cout << res << endl;
	return 0;
}
