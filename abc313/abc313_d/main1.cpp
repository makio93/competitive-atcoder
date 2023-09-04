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

const int INF = (int)(1e9);
int query(unordered_set<int> st) {
	vector<int> lst(all(st));
	int m = lst.size();
	sort(all(lst));
	cout << "? ";
	rep(i, m) cout << (lst[i]+1) << (i<m-1?' ':'\n');
	cout.flush();
	int ti;
	cin >> ti;
	return ti;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> q(n), res(n);
	rep(i, k+1) {
		unordered_set<int> tst;
		rep(j, k+1) tst.insert(j);
		tst.erase(i);
		q[i] = query(tst);
	}
	int ai = accumulate(q.begin(), q.begin()+k+1, 0) % 2;
	rep(i, k+1) res[i] = (ai - q[i] + 2) % 2;
	int si = accumulate(res.begin(), res.begin()+k-1, 0) % 2;
	rep3(i, k+1, n) {
		unordered_set<int> tst;
		rep(j, k-1) tst.insert(j);
		tst.insert(i);
		q[i] = query(tst);
		res[i] = (q[i] - si + 2) % 2;
	}
	cout << "! ";
	rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	cout.flush();
	return 0;
}
