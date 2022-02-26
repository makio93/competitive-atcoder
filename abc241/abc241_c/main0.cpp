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
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	rep(i, n) rep(j, n) if (i+5<n || j+5<n) {
		int cnt = 0;
		if (j+5 < n) {
			rep(i2, 6) if (s[i][j+i2] == '#') ++cnt;
			if (cnt >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (i+5 < n) {
			cnt = 0;
			rep(i2, 6) if (s[i+i2][j] == '#') ++cnt;
			if (cnt >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		if (i+5<n && j+5<n) {
			cnt = 0;
			rep(i2, 6) if (s[i+i2][j+i2] == '#') ++cnt;
			if (cnt >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
			cnt = 0;
			rep(i2, 6) if (s[i+i2][j+5-i2] == '#') ++cnt;
			if (cnt >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
