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

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	vector<int> ls(n), rs, lt(m), rt;
	rep(i, n) ls[i] = s[i] - '0';
	rs = ls;
	rep(i, n) rs[i] = 1 - ls[i];
	rep(i, m) lt[i] = t[i] - '0';
	reverse(all(lt));
	rt = lt;
	rep(i, m) rt[i] = 1 - lt[i];
	ls = convolution(ls, rt), rs = convolution(rs, lt);
	int res = INF;
	rep3(i, m-1, n) res = min(res, ls[i]+rs[i]);
	cout << res << endl;
	return 0;
}
