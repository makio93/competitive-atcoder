#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

const ll mod = 998244353LL;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	rep(i, n) {
		int ti;
		cin >> ti;
		rep(j, ti) {
			int ai;
			cin >> ai;
			a[i][ai-1] = 1;
		}
	}
	vector<int> s(m);
	rep(i, m) cin >> s[i];
	int ri = 0;
	rep(i, m) {
		bool exist = false;
		rep3(j, ri, n) if (a[j][i] == 1) {
			if (j != ri) swap(a[j], a[ri]);
			exist = true;
			break;
		}
		if (exist) {
			rep(j, n) if (j!=ri && a[j][i]==1) {
				rep3(j2, i, m) a[j][j2] ^= a[ri][j2];
			}
			if (s[i] == 1) {
				rep3(j, i, m) s[j] ^= a[ri][j];
			}
			++ri;
		}
	}
	if (s == vector<int>(m)) {
		ll res = 1;
		rep(i, (n-ri)) res = res * 2 % mod;
		cout << res << endl;
	}
	else cout << 0 << endl;
	return 0;
}
