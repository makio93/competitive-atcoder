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

// 本番AC

const ll mod = 998244353LL;

int main() {
	int n, k;
	cin >> n >> k;
	vector<char> c(k);
	vector<int> ki(k);
	rep(i, k) {
		cin >> c[i] >> ki[i];
		ki[i]--;
	}
	vector<bool> status(n);
	vector<ll> lsub(n), rsub(n);
	rep(i, k) {
		status[ki[i]] = true;
		if (c[i] == 'L') lsub[ki[i]]++;
		else rsub[ki[i]]++;
	}
	vector<ll> cnt(n);
	rep(i, n) {
		if (!status[i]) cnt[i] = (cnt[i] + lsub[i]) % mod;
		if (i+1 < n) lsub[i+1] = (lsub[i+1] + lsub[i]) % mod;
	}
	repr(i, n) {
		if (!status[i]) cnt[i] = (cnt[i] + rsub[i]) % mod;
		if (i-1 >= 0) rsub[i-1] = (rsub[i-1] + rsub[i]) % mod;
	}
	ll res = 1;
	rep(i, n) if (!status[i]) res = res * cnt[i] % mod;
	cout << res << endl;
	return 0;
}
