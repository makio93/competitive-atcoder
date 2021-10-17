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

// 本番終了後,自力AC

int op(int a, int b) { return min(a, b); }
int e() { return (int)(1e9); }
int mapping(int x, int a) { return (a + x); }
int composition(int x, int y) { return (x + y); }
int id() { return 0; }

int main() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<int> vals(n);
	rep(i, n) {
		if (s[i] == '(') vals[i] = 1;
		else vals[i] = -1;
	}
	vector<int> sum(n);
	sum[0] = vals[0];
	rep3(i, 1, n) sum[i] += sum[i-1] + vals[i];
	lazy_segtree<int, op, e, int, mapping, composition, id> st(n+1);
	rep(i, n) st.set(i, sum[i]);
	rep(i, q) {
		int ti;
		cin >> ti;
		if (ti == 1) {
			int li, ri;
			cin >> li >> ri;
			--li; --ri;
			if (vals[li] != vals[ri]) {
				if (vals[li]-vals[ri] == 2) st.apply(li, ri, -2);
				else st.apply(li, ri, 2);
				swap(vals[li], vals[ri]);
			}
		}
		else {
			int li, ri;
			cin >> li >> ri;
			--li; --ri;
			int sval = st.get(ri) - (li-1>=0 ? st.get(li-1) : 0);
			if (sval != 0) {
				cout << "No" << endl;
				continue;
			}
			int mval = st.prod(li, ri+1) - (li-1>=0 ? st.get(li-1) : 0);
			if (mval >= 0) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
