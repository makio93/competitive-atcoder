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

// 解説AC1,セグ木

pair<int, int> op(pair<int, int> a, pair<int, int> b) { return { min(a.first, a.second+b.first), a.second+b.second }; }
pair<int, int> e() { return { 0, 0 }; }

int main() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<pair<int, int>> vals(n);
	rep(i, n) {
		if (s[i] == '(') vals[i] = { 0, 1 };
		else vals[i] = { -1, -1 };
	}
	segtree<pair<int, int>, op, e> st(vals);
	rep(i, q) {
		int ti, li, ri;
		cin >> ti >> li >> ri;
		--li; --ri;
		if (ti == 1) {
			swap(vals[li], vals[ri]);
			st.set(li, vals[li]);
			st.set(ri, vals[ri]);
		}
		else {
			auto pi = st.prod(li, ri+1);
			if (pi.first>=0 && pi.second==0) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
