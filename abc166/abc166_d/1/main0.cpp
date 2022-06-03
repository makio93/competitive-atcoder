// バチャ参加,自力AC

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
	ll x;
	cin >> x;
	auto isfive = [](ll val) -> ll {
		ll nval = 0;
		while (nval*nval*nval*nval*nval <= val) {
			if (nval*nval*nval*nval*nval == val) return nval;
			++nval;
		}
		return -1;
	};
	ll aval = 0, bval = 0;
	while (1) {
		if (aval*aval*aval*aval*aval <= x) {
			bval = isfive(x-aval*aval*aval*aval*aval);
			if (bval != -1) {
				bval = -bval;
				break;
			}
		}
		else {
			bval = isfive(aval*aval*aval*aval*aval-x);
			if (bval != -1) break;
		}
		++aval;
	}
	cout << aval << ' ' << bval << endl;
	return 0;
}
