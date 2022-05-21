// 自力AC

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
const ll mod = (ll)(1e9) + 7;

int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	rep(i, n) cin >> t[i];
	sort(all(t));
	vector<int> sum(n+1);
	rep(i, n) sum[i+1] = sum[i] + t[i];
	ll res1 = 0;
	rep3(i, 1, n+1) res1 += sum[i];
	unordered_map<int, int> tcnt;
	rep(i, n) tcnt[t[i]]++;
	ll res2 = 1;
	for (auto pi : tcnt) {
		ll fact = 1;
		rep3(i, 1, pi.second+1) fact = fact * i % mod;
		res2 = res2 * fact % mod;
	}
	cout << res1 << endl;
	cout << res2 << endl;
	return 0;
}
