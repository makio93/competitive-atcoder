// 終了後,AC

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

using mint = modint998244353;

int main() {
	int n, l;
	cin >> n >> l;
	vector<int> s(n);
	rep(i, n) {
		string si;
		cin >> si;
		rep(j, (int)(si.size())) s[i] |= (1<<(si[j]-'a'));
	}
	mint res = 0;
	rep3(i, 1, (1<<n)) {
		int sval = (1<<26) - 1;
		rep(j, n) if ((i>>j)&1) sval &= s[j];
		if (sval != 0) {
			int m = __builtin_popcount(sval);
			mint val = mint(m).pow(l);
			if (__builtin_popcount(i)%2 != 0) res += val;
			else res -= val;
		}
	}
	cout << res.val() << endl;
	return 0;
}
