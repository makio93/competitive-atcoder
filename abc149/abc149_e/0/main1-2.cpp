// 解説AC2

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
	ll m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int mval = *max_element(all(a));
	vector<ll> acnt1(mval+1), acnt2;
	rep(i, n) acnt1[a[i]]++;
	acnt2 = acnt1;
	auto mlst = convolution_ll(acnt1, acnt2);
	int mlen = mlst.size();
	ll res = 0, sum = 0;
	repr(i, mlen) {
		ll tval = min(m-sum, mlst[i]);
		res += tval * i;
		sum += tval;
		if (sum >= m) break;
	}
	cout << res << endl;
	return 0;
}
