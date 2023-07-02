// 解説AC

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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "Yes" << endl;
			cout << 1 << ' ' << endl;
			continue;
		}
		if (n == 2) {
			cout << "No" << endl;
			continue;
		}
		set<int> st;
		rep3(i, 1, n) st.insert(i*(i+1));
		vector<int> res;
		if (st.find(n) == st.end()) {
			for (const int& vi : st) res.push_back(vi);
			res.push_back(n);
		}
		else {
			st.clear();
			rep3(i, 1, n-1) st.insert(i*(i+1));
			st.insert(n-1);
			res.push_back(2);
			for (const int& vi : st) res.push_back(vi*2);
		}
		cout << "Yes" << endl;
		rep(i, n) cout << res[i] << ' ';
		cout << endl;
	}
	return 0;
}
