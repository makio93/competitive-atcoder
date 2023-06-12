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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int mval = 10 * n;
	vector<int> buf1(mval*2+1), buf2(mval*2+1), buf3(mval*2+1);
	int *dp1 = &buf1[0] + mval, *dp2 = &buf2[0] + mval, *dp3 = &buf3[0] + mval;
	dp1[a[0]] = dp2[0] = true;
	rep3(i, 1, n) {
		rep3(j, -mval, mval+1) dp3[j] = false;
		if (i%2 == 0) {
			rep3(j, -mval, mval-a[i]+1) dp3[j+a[i]] |= dp1[j], dp3[j] |= dp1[j+a[i]];
			swap(dp3, dp1);
		}
		else {
			rep3(j, -mval, mval-a[i]+1) dp3[j+a[i]] |= dp2[j], dp3[j] |= dp2[j+a[i]];
			swap(dp3, dp2);
		}
	}
	if (dp1[x] && dp2[y]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
