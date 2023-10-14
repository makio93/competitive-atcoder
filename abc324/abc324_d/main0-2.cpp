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
	string s;
	cin >> n >> s;
	vector<int> vcnt(10);
	rep(i, n) vcnt[s[i]-'0']++;
	ll mx = 1;
	rep(i, n) mx *= 10;
	string ts = s;
	sort(all(ts));
	ll sval = stoll(ts);
	ll res = 0;
	for (ll i=0; i*i<mx; ++i) {
		string t = to_string(i*i);
		sort(all(t));
		ll tval = stoll(t);
		if (sval == tval) ++res;
	}
	cout << res << endl;
	return 0;
}
