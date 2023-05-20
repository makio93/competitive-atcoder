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
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<int> ord(n);
	iota(all(ord), 0);
	bool res = false;
	do {
		bool ok = true;
		rep(i, n-1) {
			int cnt = 0;
			rep(j, m) if (s[ord[i]][j] != s[ord[i+1]][j]) ++cnt;
			if (cnt != 1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			res = true;
			break;
		}
	} while (next_permutation(all(ord)));
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
