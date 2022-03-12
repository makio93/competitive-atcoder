// 本番AC

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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	unordered_set<int> st1, st2, bst;
	rep(i, n) if (a[i] == b[i]) st1.insert(a[i]);
	rep(i, n) bst.insert(b[i]);
	rep(i, n) if (a[i]!=b[i] && bst.find(a[i])!=bst.end()) st2.insert(a[i]);
	cout << (int)(st1.size()) << endl;
	cout << (int)(st2.size()) << endl;
	return 0;
}
