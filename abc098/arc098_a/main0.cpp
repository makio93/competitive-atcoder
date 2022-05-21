// 自力AC

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
	string s;
	cin >> n >> s;
	vector<int> lcnt(n+1), rcnt(n+1);
	rep(i, n) lcnt[i+1] = lcnt[i] + (s[i]=='W' ? 1 : 0);
	repr(i, n) rcnt[i] = rcnt[i+1] + (s[i]=='E' ? 1 : 0);
	int res = INF;
	rep(i, n) res = min(res, lcnt[i]+rcnt[i+1]);
	cout << res << endl;
	return 0;
}
