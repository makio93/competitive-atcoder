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
	int n;
	string s;
	cin >> n >> s;
	vector<pair<char, int>> runs;
	runs.emplace_back(s[0], 1);
	rep3(i, 1, n) {
		if (s[i] == runs.back().first) runs.back().second++;
		else runs.emplace_back(s[i], 1);
	}
	ll res = 0;
	int m = runs.size();
	rep(i, m) res += (ll)runs[i].second * (runs[i].second-1) / 2;
	cout << res << endl;
	return 0;
}
