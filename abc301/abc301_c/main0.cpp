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
vector<char> clst = { 'a', 't', 'c', 'o', 'd', 'e', 'r', '@' };

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.length(), slen = 0, tlen = 0;
	vector<int> scnt(8), tcnt(8);
	vector<char> slst, tlst;
	rep(i, n) {
		if (find(all(clst), s[i]) != clst.end()) scnt[find(all(clst), s[i]) - clst.begin()]++, ++slen;
		else slst.push_back(s[i]);
	}
	rep(i, n) {
		if (find(all(clst), t[i]) != clst.end()) tcnt[find(all(clst), t[i]) - clst.begin()]++, ++tlen;
		else tlst.push_back(t[i]);
	}
	sort(all(slst));
	sort(all(tlst));
	if (slen!=tlen || slst!=tlst) cout << "No" << endl;
	else {
		int val = scnt[7] + tcnt[7];
		rep(i, 7) val += min(scnt[i], tcnt[i]);
		if (val >= slen) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
