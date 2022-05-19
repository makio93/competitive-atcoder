// 学習1回目,自力AC

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
	int l, q;
	cin >> l >> q;
	set<int> st;
	st.insert(0);
	st.insert(l);
	rep(i, q) {
		int ci, xi;
		cin >> ci >> xi;
		if (ci == 1) st.insert(xi);
		else {
			auto itr = st.lower_bound(xi);
			int res = *itr - *prev(itr);
			cout << res << endl;
		}
	}
	return 0;
}
