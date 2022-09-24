// 本番WA

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
	cin >> n >> k;
	vector<int> a(k);
	rep(i, k) cin >> a[i];
	int id = k - 1, cnt1 = 0, cnt2 = 0, rcnt = 0;
	while (n) {
		while (n < a[id]) --id;
		if (rcnt%2 == 0) cnt1 += a[id];
		else cnt2 += a[id];
		n -= a[id];
		++rcnt;
	}
	cout << cnt1 << endl;
	return 0;
}
