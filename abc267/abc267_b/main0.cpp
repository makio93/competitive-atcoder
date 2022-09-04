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

const vector<int> cids = { 3, 2, 4, 1, 3, 5, 0, 2, 4, 6 };

int main() {
	string s;
	cin >> s;
	if (s[0] == '1') {
		cout << "No" << endl;
		return 0;
	}
	vector<bool> clst(7);
	rep(i, 10) if (s[i] == '1') clst[cids[i]] = true;
	bool res = false;
	rep(i, 7) {
		rep3(j, i+2, 7) if (clst[i] && clst[j]) {
			bool ok = true;
			rep3(ii, i+1, j) if (clst[ii]) ok = false;
			if (ok) {
				res = true;
				break;
			}
		}
		if (res) break;
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
