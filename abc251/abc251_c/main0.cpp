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
	vector<string> s(n);
	vector<int> t(n);
	rep(i, n) cin >> s[i] >> t[i];
	unordered_map<string, pair<int, int>> st;
	rep(i, n) if (st.find(s[i]) == st.end()) st[s[i]] = { t[i], i };
	pair<int, int> res = { -1, -1 };
	for (auto pi : st) res = max(res, { pi.second.first, -pi.second.second });
	cout << (-res.second+1) << endl;
	return 0;
}
