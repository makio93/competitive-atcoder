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

// 自力AC

int main() {
	int n;
	cin >> n;
	vector<int> c(3);
	rep(i, 3) cin >> c[i];
	sort(c.rbegin(), c.rend());
	int res = (int)(1e9);
	for (int a=n/c[0]; a>=0; --a) {
		int n2 = n - c[0] * a;
		if (n2/c[1] >= 10000-a) break;
		for (int b=n2/c[1]; b>=0; --b) {
			int n3 = n2 - c[1] * b;
			if (n3/c[2] >= 10000-a-b) break;
			if (n3%c[2] == 0) res = min(res, a+b+n3/c[2]);
		}
	}
	cout << res << endl;
	return 0;
}
