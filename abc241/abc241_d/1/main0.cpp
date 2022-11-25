// 学習1,自力AC

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
	int q;
	cin >> q;
	multiset<ll> a;
	rep(i, q) {
		int qi;
		ll x;
		cin >> qi >> x;
		if (qi == 1) a.insert(x);
		else if (qi == 2) {
			int k;
			cin >> k;
			auto itr = a.upper_bound(x);
			ll res = -1;
			while (k>0 && itr!=a.begin()) {
				--itr;
				--k;
			}
			if (k == 0) res = *itr;
			cout << res << endl;
		}
		else {
			int k;
			cin >> k;
			auto itr = a.lower_bound(x);
			ll res = -1;
			while (k>1 && itr!=a.end()) {
				++itr;
				--k;
			}
			if (k==1 && itr!=a.end()) res = *itr;
			cout << res << endl;
		}
	}
	return 0;
}
