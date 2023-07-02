// 本番TLE

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

using mint = modint1000000007;

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "Yes" << endl;
			cout << 1 << endl;
			continue;
		}
		if (n == 2) {
			cout << "No" << endl;
			continue;
		}
		set<int> st;
		st.insert(3);
		st.insert(6);
		while ((int)(st.size()) < n-1) {
			int tval = *st.begin();
			st.erase(*st.begin());
			int si = 2;
			while (1) {
				if (st.find(si) != st.end()) {
					++si;
					continue;
				}
				mint rtval = mint(tval).inv() - mint(si).inv();
				if (rtval.val() == 0) {
					++si;
					continue;
				}
				mint rval = rtval.inv();
				int ri = rval.val();
				if (st.find(ri) != st.end() || ri == si) {
					++si;
					continue;
				}
				if (((ll)ri*si) != (ll)tval*((ll)ri+si)) {
					++si;
					continue;
				}
				st.insert(si);
				st.insert(ri);
				break;
			}
		}
		vector<int> res;
		res.push_back(2);
		while (!st.empty()) {
			res.push_back(*st.begin());
			st.erase(st.begin());
		}
		cout << "Yes" << endl;
		rep(i, n) cout << res[i] << ' ';
		cout << endl;
	}
	return 0;
}
