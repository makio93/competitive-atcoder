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
	int n, k;
	string s;
	cin >> n >> k >> s;
	int res = n;
	rep3(i, 1, n+1) if (n%i == 0) {
		vector<vector<int>> ccnt(i, vector<int>(26));
		rep(j, n) ccnt[j%i][s[j]-'a']++;
		int kcnt = 0;
		rep(j, i) {
			int mval = 0;
			rep(j2, 26) mval = max(mval, ccnt[j][j2]);
			kcnt += n / i - mval;
		}
		if (kcnt <= k) {
			res = i;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
