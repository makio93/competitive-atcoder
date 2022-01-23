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
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	unordered_set<string> t;
	rep(i, n) cin >> s[i];
	rep(i, m) {
		string ti;
		cin >> ti;
		t.insert(ti);
	}
	rep(i, n) {
		if (t.find(s[i]) != t.end()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
