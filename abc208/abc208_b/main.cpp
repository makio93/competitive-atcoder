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

int main() {
	ll p;
	cin >> p;
	vector<ll> cost(11, 1);
	for (ll i=1; i<=10; ++i) cost[i] = cost[i-1] * i;
	int cnt = 0, id = 10;
	while (p > 0) {
		while (p < cost[id]) --id;
		p -= cost[id];
		++cnt;
	}
	cout << cnt << endl;
	return 0;
}
