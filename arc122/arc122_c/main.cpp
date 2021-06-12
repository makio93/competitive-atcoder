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

// 本番中、誤答、TLE

int main() {
	ll n;
	cin >> n;
	ll x = n;
	ll y = ((ll)round(x*0.618));
	vector<int> res;
	if (x%2LL == y%2LL) {
		ll to = (ll)round(x*0.618);
		if (y > to) {
			--y;
			res.push_back(2);
		}
		else {
			--x;
			res.push_back(1);
		}
	}
	while (!(x==0LL && y==0LL)) {
		if (x > y) {
			if (x%2LL == y%2LL) {
				ll to = (ll)round(x*0.618);
				 {
					--y;
					res.push_back(2);
				}
				/*
				else {
					--x;
					res.push_back(1);
				}
				*/
			}
			x -= y;
			res.push_back(3);
		}
		else if (x < y) {
			if (x%2LL == y%2LL) {
				ll to = (ll)round(y*0.618);
				 {
					--x;
					res.push_back(1);
				}
				/*
				else {
					--y;
					res.push_back(2);
				}
				*/
			}
			y -= x;
			res.push_back(4);
		}
		else {
			x = 0;
			res.push_back(3);
			/*
			while (y != 0LL) {
				--y;
				cout << y << endl;
				//exit(0);
				res.push_back(2);
			}
			*/
			if (y > 0) {
				for (ll i=0; i<y; ++i) res.push_back(2);
				break;
			}
		}
	/*
	else {
		if (x > 0LL) {
			while (x > 0LL) {
				--x;
				res.push_back(1);
			}
		}
		else {
			while (y > 0LL) {
				--y;
				res.push_back(2);
			}
		}
	}
	*/
	}
	reverse(all(res));
	int k = (int)(res.size());
	cout << k << endl;
	rep(i, k) cout << res[i] << endl;
	return 0;
}
