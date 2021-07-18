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

// 本番中、未完

int main() {
	int t;
	cin >> t;
	rep(i0, t) {
		ll n;
		cin >> n;
		ll ten = 1;
		int kcnt = 1;
		while (ten <= n/10) {
			ten *= 10;
			++kcnt;
		}
		vector<vector<int>> dcnt(kcnt, vector<int>(3));
		repr(i, kcnt) {
			rep3r(j, 1, 4) {
				while (n >= ten*j) {
					n -= ten*j;
					dcnt[i][j-1]++;
				}
			}
		}
		int res = 0;
		bool same = true;
		int mval = 0;
		rep(i, kcnt) {
			
		}
	}
	return 0;
}
