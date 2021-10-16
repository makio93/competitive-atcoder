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
	vector<int> v;
	bool gold = true;
	rep(i, n-1) {
		if (a[i+1]-a[i] > 0) {
			if (gold) v.push_back(0);
			else {
				v.push_back(1);
				gold = !gold;
			}
		}
		else if (a[i+1]-a[i] < 0) {
			if (gold) {
				v.push_back(1);
				gold = !gold;
			}
			else v.push_back(0);
		}
		else v.push_back(0);
	}
	if (!gold) v.push_back(1);
	rep(i, n) printf("%d%c", v[i], (i<n-1?' ':'\n'));
	return 0;
}
