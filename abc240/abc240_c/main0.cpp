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

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	unordered_set<int> vals;
	vals.insert(0);
	rep(i, n) {
		unordered_set<int> nvals;
		for (int val : vals) {
			nvals.insert(val+a[i]);
			nvals.insert(val+b[i]);
		}
		swap(nvals, vals);
	}
	if (vals.find(x) != vals.end()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
