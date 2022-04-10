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
	vector<string> s(n), t(n);
	rep(i, n) cin >> s[i] >> t[i];
	unordered_map<string, int> scnt;
	rep(i, n) {
		scnt[s[i]]++;
		scnt[t[i]]++;
	}
	bool ok = true;
	rep(i, n) {
		if (s[i] == t[i]) {
			if (scnt[s[i]] > 2) ok = false;
		}
		else {
			if (scnt[s[i]]>1 && scnt[t[i]]>1) ok = false;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
