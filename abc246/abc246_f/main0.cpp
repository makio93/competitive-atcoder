// 本番,誤答

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
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	mint res = 0;
	rep3(i, 1, (1<<n)) {
		bool fir = true;
		unordered_set<char> cst;
		rep(j, n) if ((i>>j)&1) {
			if (fir) {
				fir = false;
				for (char ci : s[j]) cst.insert(ci);
			}
			else {
				unordered_set<char> nst;
				for (char ci : s[j]) if (cst.find(ci) != cst.end()) nst.insert(ci);
				swap(nst, cst);
			}
		}
		int m = cst.size();
		if (m > 0) {
			mint val = mint(l).pow(m);
			if (__builtin_popcount(i)%2 == 0) res += val;
			else res -= val;
		}
	}
	cout << res.val() << endl;
	return 0;
}
