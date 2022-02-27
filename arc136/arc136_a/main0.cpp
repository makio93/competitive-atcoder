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
	string s;
	cin >> n >> s;
	string t;
	for (int i=0; i<n; ++i) {
		if (s[i] == 'A') t += string("BB");
		else t.push_back(s[i]);
	}
	int m = t.size();
	string res;
	for (int i=0; i<m; ++i) {
		if (t[i] == 'B') {
			if (i+1<m && t[i+1]=='B') {
				res += string("A");
				++i;
			}
			else res.push_back(t[i]);
		}
		else res.push_back(t[i]);
	}
	cout << res << endl;
	return 0;
}
