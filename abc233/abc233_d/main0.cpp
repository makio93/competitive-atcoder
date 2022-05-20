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

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> sum(n+1);
	rep(i, n) sum[i+1] += sum[i] + a[i];
	unordered_map<ll, int> scnt;
	scnt[0]++;
	ll res = 0;
	rep3(i, 1, n+1) {
		ll tar = sum[i] - k, cnt = 0;
		if (scnt.find(tar) != scnt.end()) cnt += scnt[tar];
		res += cnt;
		scnt[sum[i]]++;
	}
	cout << res << endl;
	return 0;
}
