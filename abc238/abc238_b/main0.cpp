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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int nval = 0;
	vector<int> cnt;
	cnt.push_back(nval);
	cnt.push_back(360);
	rep(i, n) {
		nval = (nval + a[i]) % 360;
		cnt.push_back(nval);
	}
	sort(all(cnt));
	int res = 0, m = cnt.size();
	rep(i, m-1) res = max(res, cnt[i+1]-cnt[i]);
	cout << res << endl;
	return 0;
}
