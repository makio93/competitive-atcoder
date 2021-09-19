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

// 本番WA2

const ll mod = 998244353LL;

int main() {
	ll n;
	cin >> n;
	ll res = 0;
	set<ll> sqs;
	sqs.insert(0);
	ll x = 1;
	while (x <= min((ll)(1e5),n)) {
		sqs.insert(x*x);
		auto itr = sqs.lower_bound(x*x-n);
		if (*itr == *prev(sqs.end())) break;
		if (*itr == 0LL) res = (res + (int)(sqs.size())-1) % mod;
		else res = (res + ((ll)(sqs.size())-1) - (ll)distance(sqs.begin(), itr)) % mod;
		++x;
	}
	cout << res << endl;
	return 0;
}
