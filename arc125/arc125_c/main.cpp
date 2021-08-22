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

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	rep(i, k) cin >> a[i];
	vector<vector<int>> vals(k+1);
	rep3(j, 1, a[0]) vals[1].push_back(j);
	rep(i, k-1) rep3(j, a[i]+1, a[i+1]) vals[i+2].push_back(j);
	rep3(j, a[k-1]+1, n+1) vals[0].push_back(j);
	vector<int> res;
	sort(vals[0].rbegin(), vals[0].rend());
	for (int vi : vals[0]) res.push_back(vi);
	rep(i, k) {
		res.push_back(a[i]);
		sort(vals[i+1].rbegin(), vals[i+1].rend());
		for (int vi : vals[i+1]) res.push_back(vi);
	}
	rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
	return 0;
}
