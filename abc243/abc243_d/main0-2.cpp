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
	ll x;
	cin >> n >> x;
	string s;
	cin >> s;
	stack<char> st;
	repr(i, n) {
		if (!st.empty() && st.top()=='U' && s[i]!='U') st.pop();
		else st.push(s[i]);
	}
	string t;
	while (!st.empty()) t.push_back(st.top()), st.pop();
	int m = t.length();
	__int128_t tmpx = x;
	rep(i, m) {
		if (t[i] == 'U') tmpx /= 2;
		else if (t[i] == 'L') tmpx *= 2;
		else if (t[i] == 'R') tmpx = tmpx * 2 + 1;
	}
	ll ans = tmpx;
	cout << ans << endl;
	return 0;
}
