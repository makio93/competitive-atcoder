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
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	vector<int> cnt(101);
	rep3(i, l1, r1) cnt[i] |= 1;
	rep3(i, l2, r2) cnt[i] |= 2;
	int res = 0;
	rep(i, 101) if (cnt[i] == 3) ++res;
	cout << res << endl;
	return 0;
}
