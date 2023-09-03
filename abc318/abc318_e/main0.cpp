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
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int>> vl(n);
	rep(i, n) vl[a[i]].push_back(i);
	ll res = 0;
	rep(i, n) {
		if ((int)(vl[i].size()) <= 1) continue;
		vector<ll> s;
		rep(j, vl[i].size()-1) s.push_back((vl[i][j+1]-vl[i][j]-1)*(ll)(j+1));
		rep(j, s.size()-1) s[j+1] += s[j];
		res += accumulate(all(s), 0LL);
	}
	cout << res << endl;
	return 0;
}
