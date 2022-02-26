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
	int q;
	cin >> q;
	multiset<ll> a;
	rep(i, q) {
		int ci;
		ll xi;
		cin >> ci >> xi;
		if (ci == 1) a.insert(xi);
		else if (ci == 2) {
			int ki;
			cin >> ki;
			ll val = -1;
			if (!a.empty()) {
				auto itr = a.upper_bound(xi);
				rep(j, ki) {
					if (itr == a.begin()) break;
					--itr;
					if (j == ki-1) val = *itr;
				}
			}
			cout << val << endl;
		}
		else {
			int ki;
			cin >> ki;
			ll val = -1;
			if (!a.empty()) {
				auto itr = a.lower_bound(xi);
				rep(j, ki-1) {
					if (itr == a.end()) break;
					++itr;
				}
				if (itr != a.end()) val = *itr;
			}
			cout << val << endl;
		}
	}
	return 0;
}
