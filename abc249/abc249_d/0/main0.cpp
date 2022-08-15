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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int mval = 0;
	rep(i, n) mval = max(mval, a[i]);
	vector<int> vals(mval+1);
	rep(i, n) vals[a[i]]++;
	ll res = 0;
	rep3(i, 1, mval+1) if (vals[i] > 0) {
		for (int j=i; j<=mval; ++j) {
			if ((ll)i*j>(ll)mval) break;
			int k = i * j;
			if (vals[i]==0 || vals[j]==0 || vals[k]==0) continue;
			if (i==j && j==k) res += (ll)vals[i] * vals[i] * vals[i];
			else if (i==j || j==k) {
				if (i==j) res += (ll)vals[i] * vals[j] * vals[k];
				else if (j==k) res += (ll)vals[i] * vals[j] * vals[k] * 2;
			}
			else res += (ll)vals[i] * vals[j] * vals[k] * 2;
		}
	}
	cout << res << endl;
	return 0;
}
