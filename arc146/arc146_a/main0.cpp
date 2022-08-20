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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	vector<string> astr(3);
	rep(i, 3) astr[i] = to_string(a[i]);
	vector<int> ord(3);
	iota(all(ord), 0);
	string res("0");
	do {
		string val;
		rep(i, 3) val += astr[ord[i]];
		res = max(res, val);
	} while (next_permutation(all(ord)));
	cout << res << endl;
	return 0;
}
