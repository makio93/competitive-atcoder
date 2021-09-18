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
	string x;
	int n;
	cin >> x >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	string f;
	for (char c='a'; c<='z'; ++c) f += c;
	vector<pair<string, int>> t;
	rep(i, n) {
		string ti = s[i];
		for (char& ci : ti) {
			rep(j, 26) if (ci == x[j]) {
				ci = f[j];
				break;
			}
		}
		t.emplace_back(ti, i);
	}
	sort(all(t));
	rep(i, n) cout << s[t[i].second] << endl;
	return 0;
}
