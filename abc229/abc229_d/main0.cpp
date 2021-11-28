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

// 本番AC

int main() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.length();
	int r = 0, cnt = 0, res = 0;
	rep(l, n) {
		while (r<n && (s[r]=='X'||(s[r]=='.'&&cnt<k))) {
			if (s[r] == '.') ++cnt;
			++r;
		}
		res = max(res, r-l);
		if (s[l] == '.') --cnt;
	}
	cout << res << endl;
	return 0;
}
