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

// 自力WA

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<vector<ll>> csum(n+1, vector<ll>(26));
	repr(i, n) {
		rep(j, 26) csum[i][j] += csum[i+1][j];
		csum[i][s[i]-'a']++;
	}
	vector<ll> res(n+1);
	repr(i, n) {
		for (int j=0; i+j<n; ++j) res[i] += csum[j][s[i+j]-'a'] - csum[n-(i+j)][s[i+j]-'a'];
	}
	rep(i, n) cout << res[i] << endl;
	return 0;
}
