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

// 本番TLE

using mint = modint998244353;

int op1(int a, int b) { return min(a, b); }
int e1() { return (int)(1.5e9); }
int op2(int a, int b) { return max(a, b); }
int e2() { return 0; }

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	segtree<int, op1, e1> sg1(a);
	segtree<int, op2, e2> sg2(a);
	map<int, mint> vals;
	vals[-1] = 1;
	rep(i, n) {
		auto pvals = vals;
		for (auto pi : pvals) {
			int tval = sg2.prod(pi.first+1,i+1) - sg1.prod(pi.first+1,i+1);
			if (tval == 0) continue;
			vals[i] += mint(tval) * pi.second;
		}
	}
	cout << vals[n-1].val() << endl;
	return 0;
}
