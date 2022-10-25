// バチャ参加,学習0回目,自力WA

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
	int n;
	cin >> n;
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	unordered_set<int> st;
	st.insert(1);
	rep(i, n) {
		unordered_set<int> nst;
		int val1 = d[i], val2 = (24 - d[i]) % 24;
		for (int si : st) {
			nst.insert(si|(1<<val1));
			if (val1 != val2) nst.insert(si|(1<<val2));
		}
		swap(st, nst);
	}
	int res = 0;
	for (int si : st) {
		vector<int> vals;
		rep(i, 24) if ((si>>i)&1) vals.push_back(i);
		vals.push_back(24);
		int val = INF;
		int m = vals.size();
		rep(i, m-1) val = min(val, vals[i+1]-vals[i]);
		res = max(res, val);
	}
	cout << res << endl;
	return 0;
}
