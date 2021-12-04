#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

int main() {
	int n;
	cin >> n;
	vector<int> a(n), t(n);
	rep(i, n) cin >> a[i] >> t[i];
	vector<pair<int, int>> aid(n);
	rep(i, n) aid[i] = { a[i], i };
	sort(aid.rbegin(), aid.rend());
	ll res = aid[0].first;
	rep(i, n) {
		res = max(res, (ll)t[aid[i].second]);
		if (i+1 < n) res += aid[i].first - aid[i+1].first;
		else res += aid[n-1].first;
	}
	cout << res << endl;
	return 0;
}
