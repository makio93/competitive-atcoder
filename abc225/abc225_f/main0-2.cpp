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

// 本番WA2

int main() {
	int n, k;
	cin >> n >> k;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<pair<string, string>> t(n);
	rep(i, n) {
		while (t[i].first.length() < 50) t[i].first += s[i];
		if (t[i].first.length() > 50) t[i].first = t[i].first.substr(0, 50);
		t[i].second = s[i];
	}
	sort(all(t));
	string res;
	rep(i, k) res += t[i].second;
	cout << res << endl;
	return 0;
}
