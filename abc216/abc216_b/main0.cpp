#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<string> s(n), t(n);
	rep(i, n) cin >> s[i] >> t[i];
	set<pair<string, string>> stlist;
	rep(i, n) stlist.emplace(s[i], t[i]);
	if ((int)(stlist.size()) < n) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
