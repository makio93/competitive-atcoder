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

// 自力で解答、TLE

int main() {
	int n, k;
	cin >> n >> k;
	int res = 0;
	rep3(i, 2, n+1) {
		int val = i, pcnt = 0;
		for (int j=2; j*j<=val; ++j) {
			if (val%j == 0) {
				++pcnt;
				if (pcnt >= k) break;
				while (val%j == 0) val /= j;
			}
		}
		if (val > 1) ++pcnt;
		if (pcnt >= k) ++res;
	}
	cout << res << endl;
	return 0;
}
